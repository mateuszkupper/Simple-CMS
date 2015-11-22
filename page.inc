<?php
	class page {
		public $database; //refactoring
		private $howManySectionsFound;
		private $sectionsData;		
		private $singleSectionData;
		private $section;
				
    	public function __construct() {
    		$this->database = new database();
		}
			
		function renderSections($asectionsData) {
			$howManySectionsFound = $asectionsData->num_rows;
			for($i=0; $i<$howManySectionsFound; $i++) {				
				$singleSectionData = $asectionsData->fetch_assoc();
				$this->section[i] = new sections($singleSectionData['SectionID'], $singleSectionData['PageID'], $singleSectionData['Path'],
				$singleSectionData['Content'], $singleSectionData['Config'], $singleSectionData['Style']);
			}
		}		
		
		function includeHeader() {
			include("sections/header.php");
		}
		
		function includeFooter() {
			include("sections/footer.php");
		}
	}
?>