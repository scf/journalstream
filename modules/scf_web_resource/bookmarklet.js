/**
 * Handles responses sent from proxy 
*/
function bookmarkletMessageHandler(messageEvent) {
  console.log(messageEvent);
}


/**
 * An object representing a web resource
*/
function WebResource() {
  this.url = '';
  this.title = '';
  this.description = '';
};

/**
 * Returns document meta description
*/
WebResource.prototype.getDescription = function() {
  var metas = document.getElementsByTagName('meta');
  for(var i in metas) {
    if (typeof(metas[i].name) != 'undefined' && metas[i].name.toLowerCase() == "description") {
      return encodeURIComponent(metas[i].content);
    }   
  }
  return '';
}

/** 
 * Returns document title
 */
WebResource.prototype.getTitle = function() {
  return encodeURIComponent(document.title);
}

/**
 * Returns documents url
*/
WebResource.prototype.getUrl = function() {
  encodeURIComponent(document.location.href);
}

/**
 * Generates local iFrame/form and populates input elements 
*/
WebResource.prototype.buildProxyElements = function() {
  var localIframe = document.createElement('iframe'); 
  var remoteIframe = document.createElement('iframe');
  var localForm = document.createElement('form'); 
  localForm.setAttribute("action", this.form_action);
  localForm.setAttribute("method", "post");
  localForm.setAttribute("target", this.remote_iframe_name);
  document.body.appendChild(localIframe);
  document.body.appendChild(remoteIframe);
  localIframe.contentWindow.name = this.local_iframe_name;
  remoteIframe.contentWindow.name = this.remote_iframe_name;

  //Add Window Proxy
  var windowProxy = new Porthole.WindowProxy(decodeURIComponent('http://localhost:8888/scf_web_resource/bookmarklet/proxy'));
  windowProxy.addEventListener(function(event) {
    console.log('local iframe event triggered'); 
  });
  //Add form elements
  var add_element = function(n,v,f) {
    var input = document.createElement("input"); 
    input.type = "hidden";
    input.name = n;
    input.value = v; 
    f.appendChild(input);
  }
  add_element('url',this.url,localForm);
  add_element('title',this.title,localForm);
  add_element('description', this.description,localForm);
  //localIframe.style.display = "none";
  localIframe.setAttribute("width",100);
  localIframe.setAttribute("height",100);
  localIframe.appendChild(localForm);
  localForm.submit();
}

WebResource.prototype.init = function(form_action) {
  form_action = 'http://localhost:8888/scf_web_resource/bookmarklet/handler';
  this.url = this.getUrl(); 
  this.title = this.getTitle();
  this.description = this.getDescription();
  this.form_action = form_action;
  this.local_iframe_name = 'LOCALFRAME';
  this.remote_iframe_name = 'REMOTEFRAME';
  //Build Proxy Elements
  this.buildProxyElements();
}

var messageHandler = function(message) {
  if(typeof(message) != 'undefined') {
    var data = message.data; 
    console.log(data);
  }
}


var webresource = new WebResource;
webresource.init();

windowProxy = new Porthole.WindowProxy('http://localhost:8888/scf_web_resource/bookmarklet/proxy','CHANGEME');
windowProxy.addEventListener(messageHandler);