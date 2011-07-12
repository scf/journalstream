<?php

// $Id: biblio_style_journalstream.inc,v 1.1.4.4 2010/09/23 17:44:22 scor Exp $
/**
 * Get the style information
 *
 * @return
 *   The name of the style
 */
function biblio_style_journalstream_info() {
  return array (
    'journalstream' => 'Journal Stream Biblio Styles'
  );
}
function biblio_style_journalstream_author_options() {
  $author_options = array(
    'BetweenAuthorsDelimStandard'     =>  ', ',      //4
    'BetweenAuthorsDelimLastAuthor'   =>  ', ',    //5
    'AuthorsInitialsDelimFirstAuthor' =>  ' ',      //7
    'AuthorsInitialsDelimStandard'    =>  ' ',       //8
    'betweenInitialsDelim'            =>  '',      //9
    'initialsBeforeAuthorFirstAuthor' =>  FALSE,     //10
    'initialsBeforeAuthorStandard'    =>  FALSE,      //11
    'shortenGivenNames'               =>  TRUE,      //12
    'numberOfAuthorsTriggeringEtAl'   =>  10,        //13
    'includeNumberOfAuthors'          =>  10,        //14
    'customStringAfterFirstAuthors'   =>  ', et al.',//15
    'encodeHTML'                      =>  true
  );
  return $author_options;
}

/**
 * Apply a bibliographic style to the node
 *
 *
 * @param $node
 *   An object containing the node data to render
 * @param $base
 *   The base URL of the biblio module (defaults to /biblio)
 * @param $inline
 *   A logical value indicating if this is being rendered within the
 *   Drupal framwork (false) or we are just passing back the html (true)
 * @return
 *   The styled biblio entry
 */
function biblio_style_journalstream($node, $base = 'biblio', $inline = false) {
  module_load_include('inc', 'biblio', '/includes/biblio.contributors');

  $output = '';
  $author_options = biblio_style_journalstream_author_options();

  $authors = $editor = '';
  $primary_authors = biblio_get_contributor_category($node->biblio_contributors, 1);
  if(!empty($primary_authors)) {
    //$authors = theme('biblio_format_authors', array('contributors' => $primary_authors, 'options' => $author_options));
    $authors_list = array();
    foreach($primary_authors as $author) {
      $authors_list[] = _journalstream_format_author($author);
    }
    $authors = implode(',', $authors_list);
  }

  if (!empty ($node->biblio_citekey)&&(variable_get('biblio_display_citation_key',0))) {
    $output .= '[' . check_plain($node->biblio_citekey) . '] ';
  }
  $url = biblio_get_title_url_info($node);
  $output .= '<div class="biblio-authors">' . $authors . "</div> \n";

  // biblio-extra is a wrapper for the second line of information under the authors.
  $output .= '<div class="biblio-extra">';
  $output .= '<span class="biblio-meta">';
  if ($node->biblio_secondary_title) {
    $output .= check_plain($node->biblio_secondary_title);
  }

  if ($node->biblio_date)
    $output .= '. ' . check_plain($node->biblio_date);
  if ($node->biblio_volume)
    $output .= '; ' . check_plain($node->biblio_volume);
  if ($node->biblio_issue)
    $output .= '(' . check_plain($node->biblio_issue) . ')';
  if ($node->biblio_pages)
    $output .= ':' . check_plain($node->biblio_pages);
  if (!empty($node->field_pow_epub_date))
    $output .= '. Epub ' . $node->field_pow_epub_date[LANGUAGE_NONE][0]['safe_value'];
  $output .= '.</span>'; // End of biblio-meta

  if ($node->biblio_pubmed_id) {
    $output .= '<span class="biblio-pubmed">';
    $output .= ' <span class="pubmed-id">PMID: ' . check_plain($node->biblio_pubmed_id) . '.</span>';
    $output .= ' <span class="pubmed-abstract">' . l(t('Abstract'), 'http://www.ncbi.nlm.nih.gov/pubmed/' . $node->biblio_pubmed_id . '?dopt=Abstract', array('attributes' => array('target' => '_blank'))) . '</span>';
    $output .= '</span>';
  }

  $output .= '</div>'; // end of biblio-extra

  // Since biblio cannot pass in more context information, use the hackish arg()
  // to only display the abstact in the admin pow moderation queue.
  // @todo move into a pow theme function.
  /*
  if ($node->biblio_abst_e && user_access('view biblio abstracts') && arg(0) == 'admin')
    $output .= '<div class="biblio-abstract">Abstract: ' . check_plain($node->biblio_abst_e) . '</div>';
  */

  return filter_xss($output, array('a', 'em', 'strong', 'cite', 'blockquote', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd', 'div'));
}

function _journalstream_format_author($author) {
  $format = $author['prefix'] . ' ' . $author['lastname'] . ' ';
  $format .= !empty ($author['firstname']) ? ' ' . drupal_substr($author['firstname'], 0, 1) : '';
  $format .= !empty ($author['initials']) ? str_replace(' ', '', $author['initials']) : '';
  return $format;
}
