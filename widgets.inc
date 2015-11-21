<?php
	class widgets {
		private $widgetId;
		private $pageId;				
		private $sectionId;
		private $widgetPath;
		private $widgetContent;
		private $widgetConfig;
		private $widgetStyle;
		
		function __construct($awidgetId, $apageId, $asectionId, $awidgetPath, $awidgetContent, $awidgetConfig, $awidgetStyle) {
			$this->widgetId = $awidgetId;
			$this->pageId = $apageId;
			$this->sectionId = $asectionId;
			$this->widgetPath = $awidgetPath;
			$this->widgetContent = $awidgetContent;
			$this->widgetConfig = $awidgetConfig;
			$this->widgetStyle = $awidgetStyle;																							
	 		include($_SERVER['DOCUMENT_ROOT']."/CMS2/".$this->widgetPath);
		}
	}
?>