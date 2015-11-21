<?php	
    class database {
    	public $db;
		   	
    	function __construct() {
    		$dbInfoFilePath = fopen("db.txt", 'rb');
    		$dbInfo = fgetcsv($dbInfoFilePath, 100, ",");
    		@$this->db = new mysqli($dbInfo[0], $dbInfo[1], $dbInfo[2], $dbInfo[3]);
    	}
		
    	function queryWidgets($sectionId) {
    		$widgetsQuery = "select * from tblWidgets where PageID=".$_GET['page']." and SectionID=".$sectionId.";";
			$widgetsQueryResult = $this->db->query($widgetsQuery);
			return $widgetsQueryResult;
    	}
		
    	function querySections($page) {
    		$sectionsQuery = "select * from tblSections where PageID=".$page.";";
			$sectionsQueryResult = $this->db->query($sectionsQuery);
			return $sectionsQueryResult;
    	}
		
		function queryPages($parent) {
			$pagesQuery = 'select * from tblPages where ParentPage='.$parent.';';
			$pagesQueryResult = $this->db->query($pagesQuery);
			return $pagesQueryResult;
		}
        
        function queryArticles($page) {
            $articlesQuery = 'select * from tblArticles where PageID='.$page.";";
            $articlesQueryResult = $this->db->query($pagesQuery);
            return $articlesQueryResult;
        }
	}
?>