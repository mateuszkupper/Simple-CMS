<?php	
    class database {
    	private $db;
		   	
    	function __construct() {
    		$dbInfoFilePath = fopen("db.txt", 'rb');
    		$dbInfo = fgetcsv($dbInfoFilePath, 100, ",");
    		@$this->db = new mysqli($dbInfo[0], $dbInfo[1], $dbInfo[2], $dbInfo[3]);
    	}
		
    	function queryWidgets($query) {
    		$widgetsQuery = "select * from tblWidgets where ".$query;
			$widgetsQueryResult = $this->db->query($widgetsQuery);
			return $widgetsQueryResult;
    	}
		
    	function querySections($query) {
    		$sectionsQuery = "select * from tblSections where ".$query;
			$sectionsQueryResult = $this->db->query($sectionsQuery);
			return $sectionsQueryResult;
    	}
		
		function queryPages($query) {
			$pagesQuery = "select * from tblPages where ".$query;
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