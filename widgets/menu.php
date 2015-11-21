<?php 
    displayChildren(0);

    function displayChildren($parent) {
 	  $database = new database();
        $query = $database->queryPages($parent);
        echo "<ul>";
        while ($row = $query->fetch_assoc()) { 
            echo "<li>".$row['Name']."</li>"; 
            displayChildren($row['PageID']); 
        } 
        echo "</ul>";
    } 
?>
