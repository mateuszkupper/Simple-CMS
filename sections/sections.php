<div>
	<?php
	   echo $this->sectionContent;
	   $this->renderWidgets($this->database->queryWidgets("PageID=".$_GET['page']." and SectionID=".$this->sectionId.";"));
	?>
</div> 