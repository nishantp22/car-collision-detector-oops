# Mastering-Web3-Task
This is a repository for the Mastering Web3 Task<br>
The task was to implement OOP in any supported programming language, hence C++ has been used.<br>
A class named Car has been created which has attributes : model, make, year of manufacture, (x,y,z) coordinates and (x,y,z) componants of speed.<br>
The class also has the following methods:<br>
        1. A Constructor which would initialise the values of all the attributes through inputs provided by the user.<br>
        2. menu() : The user will be asked to input a number and based on the input, various other methods will be called.<br>
        3. printCurrentData() : This will print the data currently stored in all the attributes.<br>
        4. accelerate(): This will increase the x,y,z componants of speed based on the inputs provided by the user.<br>
        5. decelerate() : This will decrease the x,y,z componants of speed based on the inputs provided by the user.<br>
        6. move() : This will increment the current x,y,z coordinatess by the current x,y,z componants of speed.<br>
        7. distanceBetweenCars() : This method calculates the distance between two cars. It takes a Car object as an argument.<br>
        8. detectCollision() : This method will take a Car object as input and check if the self car and the car passed as argument have collided or not.<br>
        9. timeToCollision() : This method will print whether the two cars will collide in the future based on their current positions and velocities
                               and if they collide, the method will also print the time before collison and the distance of collision point from the car
                               passed as argument.<br>
<br>                               
We first take an input from the user about the number of cars present. Then we store all the cars in a vector of cars. Then we perform suitable functions on any car under consideration.<br>
<br>
The approach used to check whether the two cars will collide or not is based on their relative posiitons and relative velocity :<br> 
       1. If their relative posiiton is zero, then they have already collided.<br>
       2. If their relative position is non-zero, but their relative velocity is zero, then they can never collide<br>
       3. If both the relative position and the relative velocitites are non zero, and the the angle between them is pi radians, then they will collide, else they
          will not collide(for any two vectors A and B, if theta is the angle between them, then by using cos(theta)=A.B/|A||B|,if theta is pi i.e if relative position of one car wrt other is anti parallel to relative velocity of
          that car wrt the other car, then A.B=-|A||B|)<br>
<br>
Assumptions :<br>
      1. The cars are moving in a straight line while checking the time of collision i.e. They will not accelerate till the time of collision.<br>
      2. The user always provides valid inputs, wherever asked.<br>
      <br>
(PS-I was also thinking of incorporating inheritance, probably making a derived class named SpecialCar which would have extra paraemters such as power value which would be the time in seconds from that particular instant till which the car would be able to pass through any other car, to avoid collisions. But I could not implement the approach as I was not sure on how to use the function timeTillCollision in that case where there are two objects of different classes.)
