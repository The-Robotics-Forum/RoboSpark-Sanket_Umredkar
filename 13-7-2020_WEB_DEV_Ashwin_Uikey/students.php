<?php
include('db2.php');
if(isset($_POST['submit']))
{
    
    $stud_id=$_POST['stud_id'];
    
    $query = "SELECT * FROM `students` WHERE `stud_id`='$stud_id'";
    $run=mysqli_query($con,$query);
    $row=mysqli_num_rows($run);
    if($row==1)
    {
        echo "Login Success"."<br>";
        $user_row=mysqli_fetch_assoc($run);
        echo "<br>";
        echo "Student ID : ".$user_row['stud_id'];
        echo "<br>";
        echo "Student Name : ".$user_row['stud_name'];
        echo "<br>";
        echo "Student Branch : ".$user_row['stud_branch'];
        echo "<br>";
        //echo "Student CGPA : ".$user_row['stud_cgpa'];
        //echo "<br>";
    }
    else{
        echo "Wrong ID Entered";
    }
}
?>