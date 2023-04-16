#include<bits/stdc++.h>
using namespace std;
int i=0;
int op=0;
class Car{
    public:
        string make="";
        string model="";
        int year;
        int x=0;
        int y=0;            //setting initial coordinates and speeds to zero
        int z=0;
        int speed_x=0;
        int speed_y=0;
        int speed_z=0;
        
        
        Car(){          //this is a constructor which sets the corresponding values given by user
            cout<<"\n";
            cout<<"This is car no. "<<i+1<<"\n";
            cout<<"Enter the make of the car (e.g., Hyundai, Maruti, BMW) : ";
            cin>>make;
            cout<<"Enter the model of the car (e.g., Alto, Creta, City) : ";
            cin>>model;
            cout<<"Enter the year the car was made : ";
            cin>>year;
            cout<<"Enter the x,y,z coordinates (separated by spaces): ";
            cin>>x>>y>>z;
            cout<<"Enter the x,y,z componants of speed (separated by spaces): ";
            cin>>speed_x>>speed_y>>speed_z;
            cout<<"\nCar successfully Added\n";
            i++;
        }
        
        
        int menu(int i){     //menu which will perform different functions based on user's choice
            cout<<"\n         Select a choice for car no. "<<i+1<<"\n";
            cout<<"1. Print the data\n";
            cout<<"2. Accelerate\n";
            cout<<"3. Decelerate\n";
            cout<<"4. Move\n";
            cout<<"5. Calculate the distance between two cars\n";
            cout<<"6. Check if the car has collided with another car\n";
            cout<<"7. Check the time before collision with another car\n";
            int choice;
            cin>>choice;
            int idx;
            switch(choice){
                case 1:
                    printCurrentData();
                    op=1;
                    return -1;
                case 2:
                    int ax,ay,az;
                    cout<<"Enter increments in speeds(x,y,z, separated by spaces) : ";
                    cin>>ax>>ay>>az;
                    accelerate(ax,ay,az);
                    op=2;
                    return -1;
                case 3:
                    int dx,dy,dz;
                    cout<<"Enter decrements in speeds(x,y,z, separated by spaces) : ";
                    cin>>dx>>dy>>dz;
                    decelerate(dx,dy,dz);
                    op=3;
                    return -1;
                case 4:
                    move();
                    op=4;
                    return -1;
                case 5:
                    cout<<"Enter the numer of the second car(different from the first one, 1<=number<=n) : ";
                    cin>>idx;
                    op=5;
                    return idx-1;
                case 6:
                    cout<<"Enter the number of the second car(different from the first one, 1<=number<=n) : ";
                    cin>>idx;
                    op=6;
                    return idx-1;
                case 7:
                    cout<<"Enter the number of the second car(different from the first one, 1<=number<=n) : ";
                    cin>>idx;
                    op=7;
                    return idx-1;
            }
        }
        
        
        void printCurrentData(){        //method to print current data for a car    
            cout<<"\n";
            cout<<"Model : "<<model<<endl;
            cout<<"Make : "<<make<<endl;
            cout<<"Year the car was made : "<<year<<endl;
            printf("Coordinates : (%d,%d,%d)\n",x,y,z);
            printf("Speeds(x,y,z) : (%d,%d,%d)\n",speed_x,speed_y,speed_z);
        }
        
        
        void accelerate(int inc_x,int inc_y,int inc_z){ //method to accelerate a car   
            this->speed_x+=inc_x;       //using this-> to increment the speed of that particular car
            this->speed_y+=inc_y;
            this->speed_z+=inc_z;
            cout<<"\n           Successfully accelerated\n\n";
        }
        
        
        void decelerate(int dec_x,int dec_y,int dec_z){     //method to decelerate a car
            this->speed_x-=dec_x;
            this->speed_y-=dec_y;
            this->speed_z-=dec_z;
            cout<<"\n           Successfully decelerated\n\n";
        }
        
        
        void move(){        //method to move a car for 1 second
            x+=speed_x;
            y+=speed_y;
            z+=speed_z;
            cout<<"     Successfully moved\n\n";
        }
        
        void distanceBetweenCars(Car c){
            int d=pow((c.x-x),2)+pow((c.y-y),2)+pow((c.z-z),2);
            float dst=sqrt(d);
            cout<<"\n       The Distance between the two cars at this instant is : "<<dst<<" units\n\n";
        }
        
        void detectCollision(Car c){        //method to detect if the two cars have collided
            if(c.x==x&&c.y==y&&c.z==z){
                cout<<"\n         The two cars have collided :(\n\n";
                return;
            }
            else{
                cout<<"\n         The two cars have not yet collided :)\n\n";
                return;
            }
        }
        
        
        void timeToCollision(Car c){        /*method to detect if the two cars may collide in the future,
                                            which prints the time till collision if the two cars will collide*/
            int rx=c.x-x;
            int ry=c.y-y;
            int rz=c.z-z;
            if(rx==0&&ry==0&&rz==0){    //if relative distance is already zero then the cars will collide
                cout<<"\n     The two cars have already collided :(\n\n";
                return;
            }
            int vx=c.speed_x-speed_x;
            int vy=c.speed_y-speed_y;
            int vz=c.speed_z-speed_z;
            if(vx==0&&vy==0&&vz==0){    //if relative velocity is zero given relative distance !=0 then cars wont collide
                cout<<"\n     The two cars will not collide based on current positions and speeds:)\n\n";
                return;
            }
            int dot=rx*vx+ry*vy+rz*vz;
            int mag_r=rx*rx+ry*ry+rz*rz;
            int mag_v=vx*vx+vy*vy+vz*vz;
            if(dot==-sqrt(mag_r*mag_v)){  //checking if angle between relative distance and relative velociy is pi
                cout<<"\n     The two cars will collide based on current positions and speeds :(\n";
                cout<<"\n     The time before collision is : "<<sqrt((float)(mag_r)/(float)mag_v)<<" seconds\n\n";
                //the above line prints the distance of collision from the second car
                return;

            }
            else{
                cout<<"\n     The cars will not collide based on current positions and speeds :)\n\n";
                return;
            }
       }
};
int main(){
    vector<Car>Cars;
    int n=0;
    cout<<"Enter Number of cars : ";
    cin>>n;
    while(n--){
        Car c;              //creating n Car objects and storing them in a vector
        Cars.push_back(c);
    }
    int q=0;
    while(1){
        cout<<"\n";
        int id;
        int y=0;
        cout<<"Do you wanna analyse the cars? (Type 1 for YES and 0 for NO) : ";
        cin>>y;
        if(y!=0&&y!=1){
            cout<<"Invalid response :(\n";
            continue;
        }
        else if(y==0) {
            cout<<"\n       Okay, Bye :)";
            break;
        }
        cout<<"Enter the number of a car you wanna analyse(1<=number<=n) : ";
        cin>>id;
        int t=Cars[id-1].menu(id-1);
        switch(op){
            case 5:
                Cars[id-1].distanceBetweenCars(Cars[t]);
                break;
            case 6:
                Cars[id-1].detectCollision(Cars[t]);
                break;
            case 7:
                Cars[id-1].timeToCollision(Cars[t]);
                break;
        }
    }
    return 0;
}