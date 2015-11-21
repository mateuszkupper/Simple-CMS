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
    
        $asectionsData = $database->querySections($_GET['page']);
        $howManySectionsFound = $asectionsData->num_rows;
        for($i=0; $i<$howManySectionsFound; $i++) {             
            $singleSectionData = $asectionsData->fetch_assoc();
            echo $singleSectionData['Style'];
        }
    }
    
    function displayWidgetsStyles() {
        $database = new database();
    
        $asectionsData = $database->querySections($_GET['page']);
        $howManySectionsFound = $asectionsData->num_rows;
        for($i=0; $i<$howManySectionsFound; $i++) {             
            $singleSectionData = $asectionsData->fetch_assoc();
            
            //display widget's style for each section
            //jdo
            $awidgetsData = $database->queryWidgets($singleSectionData['SectionID']);
            $howManyWidgetsFound = $awidgetsData->num_rows;
            for($i=0; $i<$howManyWidgetsFound; $i++) {
                $singleWidgetData = $awidgetsData->fetch_assoc();
                echo $singleWidgetData['Style'];
            }
        }
    }
    
    function displayPageStyle() {
        //query one page
        //fetch data
        //count how many
        //display
    }
?>
