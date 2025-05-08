<?php
$username = "s2309318";
$password = "s2309318";
$database = "d2309318";
$link = mysqli_connect("127.0.0.1", $username, $password, $database);
$output = array();
if ($result = mysqli_query($link, "SELECT * FROM CARS")) {
    while ($row = $result->fetch_assoc()) {
        $output[] = $row;
    }
    mysqli_free_result($result);
}
mysqli_close($link);
echo json_encode($output);
?>
