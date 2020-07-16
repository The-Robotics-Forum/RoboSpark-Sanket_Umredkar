<?php

include('db.php');



if(isset($_POST['search']))
{
    $stud_id = $_POST['stud_id'];

    $query = "SELECT * FROM `students` WHERE `stud_id` = '$stud_id'";

    $run = mysqli_query($con , $query);

    $row = mysqli_num_rows($run);





}


if($row == 1)
{
    $user_row = mysqli_fetch_assoc($run);

    echo "The details of the student are : " . "<br>";

    echo "Student ID : " . $user_row['stud_id'] . "<br>";

    echo "Student Name : " . $user_row['stud_name'] . "<br>";

    echo "Branch : " . $user_row['branch'] . "<br>";

    echo "CGPA : " . $user_row['cgpa'];
    
    
    
}



?>