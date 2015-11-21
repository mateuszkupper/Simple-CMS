<html>
<head>
    <style>
    <?php
        displayPageStyle();
        displaySectionsStyles();
        displayWidgetsStyles();
    ?>
    </style>
	<title>sds</title>
</head>
<body>
	<div>
		gfc
	</div>
	
<?php
    function displaySectionsStyles() {
        $database = new database();
    
        $asectionsData = $database->querySections("PageID=".$_GET['page'].";");//change
        $howManySectionsFound = $asectionsData->num_rows;
        for($i=0; $i<$howManySectionsFound; $i++) {             
            $singleSectionData = $asectionsData->fetch_assoc();
            echo $singleSectionData['Style'];
        }
    }
    
    function displayWidgetsStyles() {
        $database = new database();
    
        $asectionsData = $database->querySections("PageID=".$_GET['page'].";");
        $howManySectionsFound = $asectionsData->num_rows;
        for($i=0; $i<$howManySectionsFound; $i++) {         
            $singleSectionData = $asectionsData->fetch_assoc();
            
            $awidgetsData = $database->queryWidgets("PageID=".$_GET['page']." and SectionID=".$singleSectionData['SectionID'].";");
            $howManyWidgetsFound = $awidgetsData->num_rows;
            for($i=0; $i<$howManyWidgetsFound; $i++) {
                $singleWidgetData = $awidgetsData->fetch_assoc();
                echo $singleWidgetData['Style'];
            }
        }
    }
    
    function displayPageStyle() {
        $database = new database();
        
        $pageQuery = "select * from tblPages where PageID=".$_GET['page'].";";
        $pageQueryResult = $database->db->query($pageQuery);
        $singlePageData = $pageQueryResult->fetch_assoc();
        echo $singlePageData['Style'];
    }
?>
