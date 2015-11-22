<?php
    ?><div id='divmenu'><?php 
    displayChildren(0);
    ?></div><?php
    function displayChildren($parent) {
 	  $database = new database();
        $query = $database->queryPages("ParentPage=".$parent.";");
        echo "<ul>";
        while ($row = $query->fetch_assoc()) { 
            echo "<li><a href='index.php?page=".$row['PageID']."'>".$row['Name']."</a></li>"; 
            displayChildren($row['PageID']); 
        } 
        echo "</ul>";
    } 
?>
