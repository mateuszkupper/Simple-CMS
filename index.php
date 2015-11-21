<?php
	include("sections.inc");
	include("widgets.inc");
	include("database.inc");
	include("page.inc");

	$page = new page();
	$page->includeHeader();	
	$page->renderSections($page->database->querySections("PageID=".$_GET['page'].";"));
	$page->includeFooter();
?>