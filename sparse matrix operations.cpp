/*
Que: Design and implement a program for sparse matrix operations of addition, multiplication and
transpose of sparse matrix for climate prediction data stored in 2D array.

*/



#include <iostream>
using namespace std;
class TripetOperations{
    const static int MAX=10;
    int data[MAX][3], len;
    public:
   TripetOperations(int row, int col, int v){
       data[0][0]= row;
       data[0][1]= col;
       data[0][2]= v;
       len=1;
   } 
    public:
    void display();
    void insert(int r,int c,int v);
    void addition(TripetOperations);
    void multiplication (TripetOperations);
    void transpose (TripetOperations);
};

//Display Function Logic
void TripetOperations::display(){
     cout<<"\n  ROW | COL | VAL \n";
    for(int i=0; i<len; i++){
       cout<<"   "<<data[i][0]<<"     "<<data[i][1]<<"     "<<data[i][2]<<"   \n";
   }
   cout<<"\n";
}

//Insert function Logic
void TripetOperations::insert(int r, int c,int v){
    if(data[0][0]<r || c>data[0][1]){
        data[0][2]=len-1;
    }else{
        data[len][0]=r;
        data[len][1]=c;
        data[len][2]=v;
        len++; 
    } 
}


//Addition function Logic
void TripetOperations::addition(TripetOperations obj2){
    int p=1, q=1;
    TripetOperations obj3(data[0][0],data[0][1],0);

//Checking Dimentions are equal or not
    if(data[0][0]!=obj2.data[0][0] || data[0][1]!=obj2.data[0][1]){
        cout<<"Matrix Dimentions not matching";
    }
    else{ 
        while(p<=len && q<=len){ 

//Checking row & col number of matrix 1 == row & col number of matrix 2
        if(data[p][0]==obj2.data[q][0]){ 
            if(data[p][1]==obj2.data[q][1]){ 
                int add= data[p][2]+obj2.data[p][2]; 
                obj3.insert(data[p][0],data[p][1],add);
                p++;q++;
            }else{
                //inserting data which have less column value
                if(data[p][1]<obj2.data[q][1]){
                    obj3.insert(data[p][0],data[p][1],data[p][2]);
                    p++;

                }else if(data[p][1]>obj2.data[q][1]){
                    obj3.insert(obj2.data[q][0],obj2.data[q][1],obj2.data[q][2]);
                    q++;
                }
            }
        }else{ 
             
//inserting data which have less row value
if(data[p][0]<obj2.data[q][0]){
                obj3.insert(data[p][0],data[p][1],data[p][2]);
                p++;
            }else if(data[p][0]>obj2.data[q][0]){
                obj3.insert(obj2.data[q][0],obj2.data[q][1],obj2.data[q][2]);
                q++;
            } 
        }
        }
    }
     obj3.display();
}

//Method for Transpose of 2nd Matrix and Multiplication of transpose and 1st matrix
void TripetOperations::transpose(TripetOperations obj2){
    int k=1; 
  TripetOperations obj_t(obj2.data[0][1],obj2.data[0][0],obj2.data[0][2]); 
   for(int i=0; i<=obj2.data[0][1];i++){ 
       for(int j=1; j<=obj2.data[0][2];j++){ 
           if(obj2.data[j][1]== i){ 
               obj_t.insert(obj2.data[j][1],obj2.data[j][0],obj2.data[j][2]); 
               k++;
           }
       }
   }
   obj_t.display();
   
                
    //  ****************** 1st multiplication logic****************  
    //Multiplication with duplicate values         
      int len1=0;
      TripetOperations obj_m(data[0][0],obj_t.data[0][0],0);
        
        for(int i=1; i<=data[0][2];i++){
                
            for(int j= 1; j<=obj_t.data[0][2]; j++){
                if(data[i][1] == obj_t.data[j][1]){
                    int mult=data[i][2]* obj_t.data[j][2];
        
                    obj_m.insert(data[i][0],obj_t.data[j][0],mult);
             len1++;
                }
            }
        }
        obj_m.data[0][2]=len1;
        cout<<"Multiplication of Triplets: \n";
        obj_m.display();
    
  // Main Multiplication Logic
    TripetOperations obj_m1(obj_m.data[0][0],obj_m.data[0][0],len1);
    int i=1;
    int j= 2;
        while(i<=obj_m1.data[0][2]){
            j=i+1;
            while(j<=obj_m1.data[0][2]){ 
              if(obj_m.data[i][0] == obj_m.data[j][0] && obj_m.data[i][1] == obj_m.data[j][1]){ 
                    int abc= obj_m.data[i][2]+ obj_m.data[j][2];
                    obj_m1.insert(obj_m.data[i][0],obj_m.data[i][1],abc); 
                }
                j++;
            }
            
            i++;
            obj_m1.insert(obj_m.data[i][0],obj_m.data[i][1],obj_m.data[i][2]);
            obj_m1.data[1][0]=obj_m.data[1][0];
            obj_m1.data[1][1]=obj_m.data[1][1];
            obj_m1.data[1][2]=obj_m.data[1][2];
     
        }
         
        
        //To display multiplication output
        int val1=0,val2=0,val3=0;
        int x=1;
        while(x<(obj_m1.data[0][2]+1)){
            int y=x+1;
            while(y<(obj_m1.data[0][2]+1)){
   if(obj_m1.data[x][0] == obj_m1.data[y][0] && obj_m1.data[x][1] ==obj_m1.data[y][1]){

 val1=obj_m1.data[y][0];
val2=obj_m1.data[y][1];
                     val3=obj_m1.data[y][2];
                   
                }y++;
            }
         x++;  
        }
     cout<<"Multiplication is:";   
     cout<<"\n  ROW | COL | VAL \n";
    for(int i=0; i<(obj_m1.data[0][2]+1); i++){
         if(obj_m1.data[i][0] == val1 && obj_m1.data[i][1] == val2 && obj_m1.data[i][2] ==  val3){   
  }else{
      cout<<"   "<<obj_m1.data[i][0]<<"     "<<obj_m1.data[i][1]<<"     "<<obj_m1.data[i][2]<<"   \n";
  } 
}
}

    int main()
{ 
   int r, c, i,v; 
   cout<<"Matrix 1: Enter num of rows: ";
   cin>>r;
   cout<<"Matrix 1: Enter num of cols: ";
   cin>>c;
   cout<<"Matrix 1: Enter num of non zero values: ";
   cin>>v;
   int tracker=v;
   TripetOperations obj1(r, c,v);
   for(i=1; i<= tracker; i++){
       cout<<"\nMatrix 1: row["<<i<<"][0]: ";
       cin>>r;
       cout<<"Matrix 1: col["<<i<<"][1]: ";
       cin>>c;
       cout<<"Matrix 1: value["<<i<<"][2]: ";
       cin>>v; 
       obj1.insert(r,c,v);
   }
   obj1.display();
   
   cout<<"Matrix 2: Enter num of rows: ";
   cin>>r;
   cout<<"Matrix 2: Enter num of cols: ";
   cin>>c;
   cout<<"Matrix 2: Enter num of non zero values: ";
   cin>>v;
   int tracker2=v;
   TripetOperations obj2(r, c,v);
   for(i=1; i<=tracker2; i++){
       cout<<"\nMatrix 2: row["<<i<<"][0]: ";
       cin>>r;
       cout<<"Matrix 2: col["<<i<<"][1]: ";
       cin>>c;
       cout<<"Matrix 2: value["<<i<<"][2]: ";
       cin>>v;
       obj2.insert(r,c,v);
       cout<<"\n";
   }
   obj2.display();
    
    while(1){ 
    cout<<"\n\n*********** Menu ***********\n";
    cout<<"1 display input Triplets\n";
    cout<<"2 Addition of Triplet\n";
    cout<<"3 Transpose & Multiplication of Triplets\n";
    cout<<"4 exit\n";
    cout<<"****************************\n\n";
   
    int choise;
    cout<<"\n Enter Your Choise:";
    cin>>choise;
    
    switch(choise){ 
        case 1:
        cout<<"\nTriplet 1: \n";
               obj1.display(); 
        cout<<"\nTriplet 2: \n";
               obj2.display(); 
            break;
        
        case 2:
                obj1.display(); 
                obj2.display(); 
                cout<<"Addition of Triplets: ";
                obj1.addition(obj2);
            break;
       
        case 3:
                cout<<"Transpose of second Matrix : \n"; 
                obj1.transpose(obj2);
            break;
        
        case 4:
                exit(0);
            break;
       
        default:
            cout<<"\nPlease Enter Valid Choise\n";
    }
    
    }
}              
