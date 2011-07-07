/*
 * Copyright (c) 2010 Nick Galbreath
 * http://code.google.com/p/stringencoders/source/browse/#svn/trunk/javascript
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
*/
base64={};base64.PADCHAR='=';base64.ALPHA='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';base64.getbyte64=function(s,i){var idx=base64.ALPHA.indexOf(s.charAt(i));if(idx==-1){throw"Cannot decode base64";}
return idx;}
base64.decode=function(s){s=""+s;var getbyte64=base64.getbyte64;var pads,i,b10;var imax=s.length
if(imax==0){return s;}
if(imax%4!=0){throw"Cannot decode base64";}
pads=0
if(s.charAt(imax-1)==base64.PADCHAR){pads=1;if(s.charAt(imax-2)==base64.PADCHAR){pads=2;}
imax-=4;}
var x=[];for(i=0;i<imax;i+=4){b10=(getbyte64(s,i)<<18)|(getbyte64(s,i+1)<<12)|(getbyte64(s,i+2)<<6)|getbyte64(s,i+3);x.push(String.fromCharCode(b10>>16,(b10>>8)&0xff,b10&0xff));}
switch(pads){case 1:b10=(getbyte64(s,i)<<18)|(getbyte64(s,i+1)<<12)|(getbyte64(s,i+2)<<6)
x.push(String.fromCharCode(b10>>16,(b10>>8)&0xff));break;case 2:b10=(getbyte64(s,i)<<18)|(getbyte64(s,i+1)<<12);x.push(String.fromCharCode(b10>>16));break;}
return x.join('');}
base64.getbyte=function(s,i){var x=s.charCodeAt(i);if(x>255){throw"INVALID_CHARACTER_ERR: DOM Exception 5";}
return x;}
base64.encode=function(s){if(arguments.length!=1){throw"SyntaxError: Not enough arguments";}
var padchar=base64.PADCHAR;var alpha=base64.ALPHA;var getbyte=base64.getbyte;var i,b10;var x=[];s=""+s;var imax=s.length-s.length%3;if(s.length==0){return s;}
for(i=0;i<imax;i+=3){b10=(getbyte(s,i)<<16)|(getbyte(s,i+1)<<8)|getbyte(s,i+2);x.push(alpha.charAt(b10>>18));x.push(alpha.charAt((b10>>12)&0x3F));x.push(alpha.charAt((b10>>6)&0x3f));x.push(alpha.charAt(b10&0x3f));}
switch(s.length-imax){case 1:b10=getbyte(s,i)<<16;x.push(alpha.charAt(b10>>18)+alpha.charAt((b10>>12)&0x3F)+
padchar+padchar);break;case 2:b10=(getbyte(s,i)<<16)|(getbyte(s,i+1)<<8);x.push(alpha.charAt(b10>>18)+alpha.charAt((b10>>12)&0x3F)+
alpha.charAt((b10>>6)&0x3f)+padchar);break;}
return x.join('');}

/*
 * Copyright (c) 2011 Nicholas G. Maloney 
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * An object representing a web resource
*/
function WebResource() {
  this.login_url = ''; 
  this.url = '';
  this.form_action = '';
  this.local_iframe_name = '';
  this.remote_iframe_name = '';
};

WebResource.prototype.localIframeMessage = function(message) {
 var d = window.frames[this.local_iframe_name].document.getElementById('message'); 
 d.innerHTML = message;
}

WebResource.prototype.hideFrame = function(self) {
  document.getElementById(self.local_iframe_name).style.display = 'none';
}

WebResource.splitMessageParameters = function(message) {
	if (typeof message == 'undefined' || message === null) {
		return null;
	}
	var hash = [];
	var pairs = message.split(/&/);
	for (var keyValuePairIndex in pairs) {
		var nameValue = (typeof(pairs[keyValuePairIndex]) == 'string') ? pairs[keyValuePairIndex].split('=') : false;
    if(nameValue) {
      if (typeof(nameValue[1]) == 'undefined') {
        hash[nameValue[0]] = '';
      } else {
        hash[nameValue[0]] = nameValue[1];
      }
    }
	}
	return hash;
};

/**
 * Generates local iFrame/form and populates input elements 
*/
WebResource.prototype.buildProxyElements = function() {
  var localIframe = document.createElement('iframe'); 
  var remoteIframe = document.createElement('iframe');
  var localForm = document.createElement('form'); 
  var message = '';
  var self = this;
  localForm.setAttribute("action", this.form_action);
  localForm.setAttribute("method", "post");
  localForm.setAttribute("target", this.remote_iframe_name);
  localIframe.style.width = '200px';
  localIframe.style.height = '200px';
  localIframe.setAttribute('style','display:block;border:3px solid #aaa; position:absolute;top:10px;left:10px;background-color:#fff');
  localIframe.setAttribute('id',this.local_iframe_name);
  document.body.appendChild(localIframe);
  document.body.appendChild(remoteIframe);
  localIframe.contentWindow.name = this.local_iframe_name;
  remoteIframe.contentWindow.name = this.remote_iframe_name;
  window.frames[this.local_iframe_name].document.write('<html><body style="color: #555; background-color: #fff; text-align: center; margin: 0px; font-family: Georgia, Times, serif; font-size: 26px;"><div id="message"></div></body</html>');
  message = 'Saving <img src="http://c631069.r69.cf2.rackcdn.com/waiting.gif">';
  this.localIframeMessage(message);
    //Add Window Proxy
  var windowProxy = new Porthole.WindowProxy(decodeURIComponent(this.proxy_url));
  windowProxy.addEventListener(function(messageEvent) {
    if(typeof(messageEvent.data) != 'undefined') {
      var params = WebResource.splitMessageParameters(messageEvent.data);
      if(typeof(params['status']) != 'undefined' && params['status'] == 1) {
        self.localIframeMessage('Saved!');
      }
      else {
        var redirect_url = self.login_url + '/' + base64.encode(self.url);
        document.location.href = redirect_url; 
      }
      setTimeout(function() {self.hideFrame(self)},3000);
    }
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
  localIframe.setAttribute("width",100); localIframe.setAttribute("height",100);
  localIframe.appendChild(localForm);
  localForm.submit();
}

WebResource.prototype.init = function(init_params) {
  var params = init_params || {};
  this.login_url = params.login_url || '';
  this.url = encodeURIComponent(document.location.href);
  this.proxy_url = params.proxy_url || '';
  this.form_action = params.form_action || '';
  this.local_iframe_name = params.local_iframe_name || 'LOCALFRAME';
  this.remote_iframe_name = params.remote_iframe_name || 'REMOTEFRAME';
  this.buildProxyElements();
}
