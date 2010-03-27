<?php // $Id: page.tpl.php,v 1.15.4.7 2008/12/23 03:40:02 designerbrent Exp $ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
<head>
	<title><?php print $head_title ?></title>
	<meta http-equiv="content-language" content="<?php print $language->language ?>" />
	<?php print $meta; ?>
  <?php print $head; ?>
  <?php print $styles; ?>
  <!--[if lte IE 7]>
    <link rel="stylesheet" href="<?php print $path; ?>news/news/ie.css" type="text/css" media="screen, projection">
  	<link href="<?php print $path; ?>css/ie.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
  <![endif]-->  
  <!--[if lte IE 6]>
  	<link href="<?php print $path; ?>css/ie6.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
  <![endif]-->  
</head>

<body class="<?php print $body_classes; ?>">


<div id="wrapper" class="clearfix">
	
  	<div id="header">
	    <h1 id="logo">
	      <a title="<?php print $site_name; ?><?php if ($site_slogan != '') print ' &ndash; '. $site_slogan; ?>" href="<?php print url(); ?>"><?php print $site_name; ?><?php if ($site_slogan != '') print ' &ndash; '. $site_slogan; ?></a>
	    </h1>
	    <?php print $header; ?>    
	</div>
	
	
	<div id="breadcrumb clearfix">
		<?php
		 if ($breadcrumb != '') {
	        print $breadcrumb;
	      }
		?>
	</div>
	
  <div class="main clearfix"> 
  	<?php if ($left): ?>
	    <div class="left"><?php print $left; ?></div>
	  <?php endif ?>
  
	  <div class="<?php print $center_classes; ?>">
		<div class="inner">
	    <?php
	      if ($tabs != '') {
	        print '<div class="tabs">'. $tabs .'</div>';
	      }

	      if ($messages != '') {
	        print '<div id="messages">'. $messages .'</div>';
	      }

	      print $help; // Drupal already wraps this one in a class      

	      print $content;
	    ?>
		</div>
	  </div>

	  <?php if ($right): ?>
	    <div class="right">
			<div class="inner">	
				<?php print $right; ?>
			</div>
		</div>	
	  <?php endif ?>
  </div>

  <?php print $scripts ?>
  <?php print $closure; ?>
  	

  <?php if ($footer_message | $footer): ?>
    <div id="footer" class="clear">
      <?php if ($footer): ?>
        <?php print $footer; ?>
      <?php endif; ?>
      <?php if ($footer_message): ?>
        <div id="footer-message"><?php print $footer_message; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>

</body>
</html>
