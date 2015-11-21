<?php
	class sections {
		private $sectionId;
		private $pageId;
		private $sectionPath;
		private $sectionContent;
		private $sectionConfig;
		private $sectionStyle;
		
		private $howManyWidgetsFound;
		private $widgetsData;		
		private $singleWidgetData;
		private $widget;
		private $database;
		
		
		function __construct($asectionId, $apageId, $asectionPath, $asectionContent,
		$asectionConfig, $asectionStyle) {
			$this->sectionId = $asectionId;
			$this->pageId = $apageId;
			$this->sectionPath = $asectionPath;
			$this->sectionContent = $asectionContent;
			$this->sectionConfig = $asectionConfig;
			$this->sectionStyle = $asectionStyle;

			$this->database = new database();		
			include($_SERVER['DOCUMENT_ROOT']."/CMS2".$this->sectionPath); //renderWidgets()
		}
				
		function renderWidgets($awidgetsData) {
			$howManyWidgetsFound = $awidgetsData->num_rows;
			for($i=0; $i<$howManyWidgetsFound; $i++) {
				$singleWidgetData = $awidgetsData->fetch_assoc();
				$this->widget[i] = new widgets($singleWidgetData['WidgetID'], $singleWidgetData['PageID'], $singleWidgetData['SectionID'], 
				$singleWidgetData['Path'], $singleWidgetData['Content'], $singleWidgetData['Config'], $singleWidgetData['Style']);
			}
		}	
	}						    
?>	