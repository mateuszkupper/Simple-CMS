<div>
sections
	<?php
		$this->renderWidgets($this->database->queryWidgets("PageID=".$_GET['page']." and SectionID=".$this->sectionId.";"));
	?>
</div> 