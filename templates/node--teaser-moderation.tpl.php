<div id="node-<?php print $node->nid; ?>-moderation-form">
  <?php print render($moderation_form); ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix journalstream-content-wrapper"<?php print $attributes; ?>>
    <div class="content journalstream-content"<?php print $content_attributes; ?>>
      <?php
        // We hide the comments and links now so that we can render them later.
        print render($content);
      ?>
    <!-- Inline Moderation Form -->
    <?php print render($inline_moderation_form); ?>
    </div><!-- /.content -->
  </div><!-- /#node-<?php print $node->nid; ?> -->
</div><!--<?php print $node->nid; ?>-moderation-form -->
