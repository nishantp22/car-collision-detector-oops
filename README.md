# Mastering-Web3-Task
This is a repository for the Mastering Web3 Task
The task was to implement OOP in any supported programming language, hence C++ has been used.
A class named Car has been created which has attributes : model, make, year of manufacture, (x,y,z) coordinates and (x,y,z) componants of speed.
The class also has the following methods:
        1. A Constructor which would initialise the values of all the attributes through inputs provided by the user.
        2. menu() : The user will be asked to input a number and based on the input, various other methods will be called.
        3. printCurrentData() : This will print the data currently stored in all the attributes.
        4. accelerate(): This will increase the x,y,z componants of speed based on the inputs provided by the user.
        5. decelerate() : This will decrease the x,y,z componants of speed based on the inputs provided by the user.
        6. move() : This will increment the current x,y,z coordinatess by the current x,y,z componants of speed.
        7. detectCollision() : This method will take a Car object as input and check if the self car and the car passed as argument have collided or not.
        8. timeToCollision() : This method will print whether the two cars will collide in the future based on their current positions and velocities
                               and if they collide, the method will also print the time during collison and the distance of collision point from the car
                               passed as argument.
                                
The approach used to check whether the two cars will collide or not is based on their relative posiitons and relative velocity : 
       1. If their relative posiiton is zero, then they have already collided.
       2. If their relative position is non-zero, but their relative velocity is zero, then they can never collide
       3. If both the relative position and the relative velocitites are non zero, and the the angle between them is pi radians, then they will collide, else they
          will not collide(using cos(theta)=A.B/|A||B|,if theta is pi i.e if relative position of one car wrt other is anti parallel to relative velocity of
          that car wrt the other car, then A.B=-|A||B|)

Assumptions :
      1. There are only two cars(if there are more than two, we can store the Car objects in a vector and run a search to check collision with a particular
         car based on its model and make).
      2. The cars are moving in a straight line while checking the time of collision i.e. They will not accelerate till the time of collision.
        
