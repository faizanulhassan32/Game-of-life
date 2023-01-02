/*

	Name : Faizan-ul-hassan
	Roll no# : 19I-1976
	Section : CS-F
	PF Project

*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Declaration of functions

// Function for drawing grid
void Drawgrid 		( bool draw[20][20] ) ;

// Function to be called in loop of generations to repeat rules and drawing grid
void Start 		( bool draw[20][20] , int[] , int[] , int , int[] , int[] , int ) ; 

// Function which starts the game and it is called in main function and also used to enter sec_x and sec_y
void start1 		( bool draw[20][20] ) ; 

// Function for finding neighbours of each live cell
void find_nei 		( bool draw[20][20] , int[] , int[] , int , int[] , int[] , int ) ;

// Function for finding live count which means the total no of live cells around every live cell
int* live_count 	( int [] , int [] , int ) ;

// Function for finding neighbour count which means the total no of live cells around every dead cell
void nei_count 	( bool draw[20][20] , int [] , int [] , int [] , int [] , int , int , int* , int)  ;

// Function in which the rules are written and the loop for generations is also implemented
void rules 		( bool draw[20][20] , int[] , int[] , int[] , int[] , int[] , int[] , int , int, int ) ;

// Function for replacing every element with -1 which should be deleted in sec_x
int replace_x 		( int[] ,int[], int , int, int ) ;

// Function for replacing every element with -1 which should be deleted in sec_y
int replace_y 		( int[] , int[], int , int, int ) ;

// Function for deleting dead cells which were previously alive and removing them from the array
int dlt 			( int[] , int , int ) ;
//=======================================MAIN function================================================
//====================================================================================================
int main()
{	// Function starting

	bool draw[20][20] = {} ;		// Declaring draw array for grid
	start1(draw);	// Calling start function
	cout<<endl;
	return 0;

}	// Function ending
//=======================================start1 function==========================================
//=====================================================================================================
void start1 ( bool draw[20][20] )
{
	int sec_x [100] = {} , sec_y [100] = {} ; 	// 2 secondry arrays for x and y axis
	int nei_x [300] = {} , nei_y [300] = {} ;  	// 2 array to store neighbours for x and y
	int no_of_cells, x, y ;
	int generations;	// Declaration for users input of generations
		
	cout<<"\nEnter the no of generations : ";
	cin>>generations;	// Taking input

	for ( ; generations<1 ; )	// Input validation
	{
	cout<<"INVALID!! Enter again : ";
	cin>>generations;
	cout<<endl;
	}

	cout<<"\nEnter the number of cells : ";
	cin>>no_of_cells;	// Taking input

		for ( ; no_of_cells<1 || no_of_cells>400 ; )	// Input validation
		{
		cout<<"INVALID!! Enter again : ";
		cin>>no_of_cells;
		cout<<endl;
		}
			for(int i=0 ; i < no_of_cells ; i++)	// Loop running until users input
			{	
				cout <<"For cell "<< i+1 << " :- "<<endl;
				cout<<"Enter X ( 0-19 ) : ";
				cin>>x;	// Taking x co-ordinate
				for ( ; x<0 || x>19 ; )		// Input validation
				{
					cout<<"Enter X again ( 0-19 ) : ";
					cin>>x;		// Taking input of x co-ordinate
				}
					sec_x[i] = x;	// Storing co-ordinate in the sec_x array
				
				cout<<"Enter Y ( 0-19 ) : ";
				cin>>y;	// Taking y co-ordinate
				
				for ( ; y<0 || y>19 ; )		// Input validation
				{
					cout<<"Enter Y again ( 0-19 ) : ";
					cin>>y;		// Taking input of x co-ordinate
				}
					sec_y[i] = y;	// Storing co-ordinate in the sec_y array
				
				cout<<endl;				
				draw [x][y] = true;		// Drawing following cell on the grid
				Drawgrid(draw);	// Calling function
			}
	
	Start (draw , sec_x , sec_y , no_of_cells , nei_x , nei_y , generations);

}
//=======================================START function================================================
//=====================================================================================================
void Start (bool draw[20][20] , int sec_x[] , int sec_y[] , int no_of_cells , int nei_x[] , int nei_y[] , int generations)
{	// Function starting

	find_nei ( draw, sec_x , sec_y , no_of_cells , nei_x , nei_y , generations );

}	// Function ending

//=======================================find_nei function==========================================
//=====================================================================================================
void find_nei ( bool draw[20][20], int sec_x[] , int sec_y[] , int no_of_cells , int nei_x[] , int nei_y[] , int generations )

{	// Function starting

	int num1 = 0 , num2 = 0 ;	// Declaration to get input of no of cells
	
	int index=0;	// Variable using to store values in neighbouring array

			for(int i=0 ; i < no_of_cells ; i++)	// Loop running until users input
			{	
									
			nei_x[index] = sec_x[i]-1;		// Calculation x-neighbour
				num1 = sec_x[i]-1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]-1;		// Calculation y-neighbour
				num2 = sec_y[i]-1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}	
				
					if (i>0)	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index

//======================================================================================================			
			
			nei_x[index] = sec_x[i];		// Calculation x-neighbour
				num1 = sec_x[i];		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]-1;		// Calculation y-neighbour
				num2 = sec_y[i]-1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index

//======================================================================================================
			
			nei_x[index] = sec_x[i]+1;		// Calculation x-neighbour
				num1 = sec_x[i]+1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]-1;			// Calculation y-neighbour
				num2 = sec_y[i]-1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index

//======================================================================================================
			
			nei_x[index] = sec_x[i]-1;		// Calculation x-neighbour
				num1 = sec_x[i]-1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i];		// Calculation y-neighbour
				num2 = sec_y[i];		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index

//======================================================================================================
			
			nei_x[index] = sec_x[i]+1;		// Calculation x-neighbour
				num1 = sec_x[i]+1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i];		// Calculation y-neighbour
				num2 = sec_y[i];		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
									index--;		// Move to previous index
									break;
							}
						}
  					}
			index++;		// Move to next index

//======================================================================================================
			
			nei_x[index] = sec_x[i]-1;		// Calculation x-neighbour
				num1 = sec_x[i]-1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]+1;		// Calculation y-neighbour
				num2 = sec_y[i]+1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index

//======================================================================================================
			
			nei_x[index] = sec_x[i];		// Calculation x-neighbour
				num1 = sec_x[i];		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]+1;		// Calculation y-neighbour
				num2 = sec_y[i]+1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int j=0 ; j<index ; j++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[j] && num2==nei_y[j] )		// If neighbour is already found in array
							{
								index--;		// Move to previous index
								break;
							}
  						}
  					}
			index++;		// Move to next index
						
//======================================================================================================
			
			nei_x[index] = sec_x[i]+1;		// Calculation x-neighbour
				num1 = sec_x[i]+1;		// Temp variable for duplication removal
			
			nei_y[index] = sec_y[i]+1;		// Calculation y-neighbour
				num2 = sec_y[i]+1;		// Temp variable for duplication removal
			
				if ( ( num1 < 0 || num1 > 19 ) ||  ( num2 < 0 || num2 > 19 ) )	// If neighbour is out of grid
				{
				index--;		// Move to previous index
				}
					if (i>0) 	// IF to execute after first repeatation
					{
  						for ( int i=0 ; i<index ; i++ )	// index = no of neighbours found
						{
							if ( num1==nei_x[i] && num2==nei_y[i] )		// If neighbour is already found in array 
							{
								index--;		// Move to previous index
								break;	
							}
						}
  					}	
			index++;		// Move to next index
//======================================================================================================			
			}		
			int* live_cells = live_count ( sec_x , sec_y , no_of_cells );		// Calling function for step3			
			
			cout<<"The live_cells count is : ";
			for (int i=0 ; i<no_of_cells ; i++ )
			{
			cout<<live_cells[i]<<"  ";
			}
			
			cout<<endl<<endl;
			cout<<">=========================<"<<endl;
			cout<<endl;
						
			int counter = 0;		
			for (int i=0; i<no_of_cells; i++)	// Loop running until users input of no of cells
			{
				counter = 0;	// Resetting counter to 0
				for (int j=0; j<index; j++) 	// Loop running until no of neigbours found because index=neighbours
				{
					if (sec_x[i] == nei_x[j] && sec_y[i] == nei_y[j])		// Checking if live cell is found
					{}			
					else 
					{
						nei_x[counter] = nei_x[j];	// If not found, store in nei_x array
						nei_y[counter] = nei_y[j];	// If not found, store in nei_y array
						counter++;	//increment counter					
					}
				}
				index = counter;	//update index to counter
			}
	
							//====================================================	
		     
			cout<<"The X-Axis for all neighbours are : "<<endl<<endl;		
			for ( int i=0 ; i<counter ; i++ )
			{
			cout<<nei_x[i]<<"  ";	// Displaying x-axis of updated neighbouring array
			}
			cout<<endl<<endl;

			cout<<"The Y-Axis for all neighbours are : "<<endl<<endl;		
			for ( int i=0 ; i<counter ; i++ )
			{
			cout<<nei_y[i]<<"  ";	// Displaying y-axis of updated neighbouring array
			}
			cout<<endl<<endl;	
			cout<<"Total elements are : "<<index<<endl;		// Displaying total no of neighbours

							//====================================================

			nei_count ( draw , sec_x , sec_y , nei_x , nei_y , index , no_of_cells , live_cells , generations);		// Calling function for step 3
						
}	// Function ending
//=======================================LIVING-CELLS count function======================================
//========================================================================================================
int* live_count ( int sec_x[] , int sec_y[] , int no_of_cells )
{	// Function starting

							//====================================================

	// Declaration and initialization
	int* live_cells = new int[no_of_cells]{0};
	int nbx [300] = {} , nby [300] = {} ; 
	int nx=0 , ny=0 ; 
	cout<<endl;
	cout<<">=========================<"<<endl;
	int index=0;
	
							//====================================================	
	
	// Calculatin neighbours again without duplication removal
	for ( int i=0 ; i<no_of_cells ; i++ )
	{
			
		nx = sec_x[i]-1;	// x co-ordinate
		ny = sec_y[i]-1;	// y co-ordinate		
		nbx[index] = nx;
		nby[index] = ny;			
		if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
		{
		index--;	// Move to previous index
		}	
		index++;	// Move to next index

		  nx = sec_x[i];	// x co-ordinate
		  ny = sec_y[i]-1;	// y co-ordinate	  
		  nbx[index] = nx;
		  nby[index] = ny;
		  if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
		  {
		  index--;	// Move to previous index
		  }	
		  index++;	// Move to next index

		    nx = sec_x[i]+1;	// x co-ordinate
		    ny = sec_y[i]-1;	// y co-ordinate
		    nbx[index] = nx;
		    nby[index] = ny;
		    if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
		    {
		    index--;	// Move to previous index
		    }
		    index++;	// Move to next index
			
			 nx = sec_x[i]-1;	// x co-ordinate
			 ny = sec_y[i];	// y co-ordinate	
			 nbx[index] = nx;
			 nby[index] = ny;
			 if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
			 {
			 index--;	// Move to previous index
			 }		
		  	 index++;		// Move to next index

			   nx = sec_x[i]+1;		// x co-ordinate
			   ny = sec_y[i];		// y co-ordinate
			   nbx[index] = nx;
			   nby[index] = ny;
			   if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
			   {
			   index--;	// Move to previous index
			   }	
   		  	   index++;	// Move to next index
			   
			     nx = sec_x[i]-1;	// x co-ordinate
			     ny = sec_y[i]+1;	// y co-ordinate			
				nbx[index] = nx;
				nby[index] = ny;
				if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
				{
				index--;	// Move to previous index
				}
			  	index++;		// Move to next index

			       nx = sec_x[i];	// x co-ordinate
			       ny = sec_y[i]+1;	// y co-ordinate				
				  nbx[index] = nx;
				  nby[index] = ny;	
				  if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
				  {
				  index--;	// Move to previous index
				  }  
		 	       index++;	// Move to next index
			       
			         nx = sec_x[i]+1;	// x co-ordinate
			         ny = sec_y[i]+1;	// y co-ordinate	
				    nbx[index] = nx;
				    nby[index] = ny;	
				    if ( ( nx < 0 || nx > 19 ) ||  ( ny < 0 || ny > 19 ) )		// Neighbour validation
			         {
				    index--;	// Move to previous index
				    }
				    index++;	// Move to next index
		
	}
							//====================================================
							
	// For loop to keep count of repeating live cells in an array
	cout<<endl;

	for ( int i=0 ; i<no_of_cells ; i++ )
	{
		for ( int j=0 ; j<index ; j++ )
		{
			if ( sec_x[i] == nbx[j] && sec_y[i] == nby[j] )	// If live cell is found in the neighbours
			{
			live_cells[i]++;	// Incrementing
			}
		}
	}
	
	return live_cells;	
	  
}	// Function ending
//=======================================NEI-CELLS count function=========================================
//========================================================================================================

void nei_count (bool draw[20][20] , int user_x[] , int user_y[] , int nb_x[] , int nb_y[] , int index , int no_of_cells , int* live_cells , int generations)

{	// Function starting


	// Declaration and initialization
	int nei_cells[index] = {0};
	int nbx [300] , nby [300] ; 
	int nx=0 , ny=0 ; 
	cout<<endl;
	cout<<">=========================<"<<endl;

							//====================================================
	
	// Calculating neighbours count
	for ( int i=0 ; i<index ; i++ )
	{

		nx = nb_x[i]-1;	// x co-ordinate
		ny = nb_y[i]-1;	// y co-ordinate		
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}
		
		nx = nb_x[i];	// x co-ordinate
		ny = nb_y[i]-1;	// y co-ordinate	  
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}

		nx = nb_x[i]+1;	// x co-ordinate
		ny = nb_y[i]-1;	// y co-ordinate
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}
			
		nx = nb_x[i]-1;	// x co-ordinate
		ny = nb_y[i];	// y co-ordinate	
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}

		nx = nb_x[i]+1;		// x co-ordinate
		ny = nb_y[i];		// y co-ordinate
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}
		   
		nx = nb_x[i]-1;	// x co-ordinate
		ny = nb_y[i]+1;	// y co-ordinate			
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}

		nx = nb_x[i];	// x co-ordinate
		ny = nb_y[i]+1;	// y co-ordinate				
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}
			       
		nx = nb_x[i]+1;	// x co-ordinate
		ny = nb_y[i]+1;	// y co-ordinate	
			for ( int j=0 ; j<no_of_cells ; j++ )
			{	
				if ( nx==user_x[j] && ny==user_y[j] )	// If equal to live cells
				{
				nei_cells[i]++;	// Increment
				}
			}
		
	}
	cout<<endl;
	cout<<"The neighbour count is : ";
	for ( int i=0 ; i<index ; i++ )
	{
	cout<<nei_cells[i]<<"  ";	// Displaying count of live cells around each neighbour
	}
	
	rules ( draw , user_x , user_y , nb_x , nb_y , live_cells , nei_cells , index , no_of_cells , generations ); // Calling function
	 	
}	// Function ending
//=======================================RULES function================================================
//========================================================================================================

void rules ( bool draw[20][20] , int sec_x[] , int sec_y[] , int nei_x[] , int nei_y[] , int live_cells[] , int nei_cells[] , int index , int no_of_cells , int generations )

{	// Function starting
	
	int nox , noy , x , y;	// Declaration to bs used in this function
	
	cout<<endl;

	cout<<"SEC_X : ";
	for ( int i=0 ; i<no_of_cells ; i++ )
	{
	cout<<sec_x[i]<<"  ";
	}
	cout<<endl;
	cout<<"SEC_Y : ";
	for ( int i=0 ; i<no_of_cells ; i++ )
	{
	cout<<sec_y[i]<<"  ";
	}
	cout<<endl;

	for ( int g=0 ; g<generations ; g++ )
	{
			for ( int k=0 ; k<no_of_cells ; k++ )	// Loop running until total no of cells
			{
				if( live_cells[k] == 2 || live_cells[k] ==3 )	// Rule 2
				{
					draw[ sec_x[k] ] [ sec_y[k] ] = true;	// Display following co-ordinate on the grid	
					Drawgrid ( draw ) ;		// Calling drawgrid function to draw grid
					cout<<endl;		
				}
				else if(live_cells[k] < 2) 	// Rule 3
				{
					draw[ sec_x[k] ] [ sec_y[k] ] = false;	// Remove following co-ordinate from the grid
					Drawgrid ( draw ) ;		// Calling drawgrid function to draw grid	
					cout<<endl;
					
					x=sec_x[k];	// Storing x co-ordinate in variable
					y = sec_y[k];	// Storing y co-ordinate in variable
					nox = replace_x ( sec_x , sec_y, no_of_cells, x, y );	// Calling func to delete x co-ordinate
					noy = replace_y ( sec_y , sec_x, no_of_cells , y, x );	// Calling func to delete y co-ordinate
					
				}
				else if(live_cells[k] > 3)	// Rule 4
				{
					draw[ sec_x[k] ] [ sec_y[k] ] = false;	// Remove following co-ordinate from the grid
					Drawgrid ( draw ) ;		// Calling drawgrid function to draw grid	
					cout<<endl;
					
					x=sec_x[k];	// Storing x co-ordinate in variable
					y = sec_y[k];	// Storing y co-ordinate in variable
					nox = replace_x ( sec_x, sec_y , no_of_cells , x, y );	// Calling func to delete x co-ordinate
					noy = replace_y ( sec_y , sec_x, no_of_cells , y, x );	// Calling func to delete y co-ordinate
											
				}
			}	

					int s;					
					// Here i wil be calling delete function to remove -1 that i have stored in place of live cells 						which become dead and they will be removed from the sec_x and sec_y
					
					s = dlt ( sec_x , no_of_cells, -1 );	
					s = dlt ( sec_y , no_of_cells, -1 );
					
					cout<<"\nX  Y"<<endl;
					for ( int i=0 ; i<s ; i++ )
					{
					cout<<sec_x[i]<<"  "<<sec_y[i]<<endl;
					}					
					
							//====================================================	

			cout<<"NEI_X : ";
			for ( int i=0 ; i<index ; i++ )
			{
			cout<<nei_x[i]<<"  ";
			}
			cout<<endl;
			
			cout<<"NEI_Y : ";
			for ( int i=0 ; i<index ; i++ )
			{
			cout<<nei_y[i]<<"  ";
			}
			cout<<endl;

			cout<<"Nei cells count : ";
			for (int i=0 ; i<index ; i++ )
			{
			cout<<nei_cells[i]<<"  ";
			}
			cout<<endl<<endl;
			
			for ( int i=0 ; i<index ; i++ )	// This loop running for neighbours rules
			{
				if ( nei_cells[i] == 3 )		// Rule 1
				{
					cout<<nei_x[i]<<"   "<<nei_y[i]<<"  Become alive"<<endl;	
					draw[ nei_x[i] ] [ nei_y[i] ] = true;	// Display following co-ordinate on the grid
					Drawgrid ( draw ) ;		// Calling drawgrid function to draw grid	
					cout<<endl;
					
					sec_x[s] = nei_x[i];	// Store x co-ordinate of new live cell in sec_x
					sec_y[s] = nei_y[i];	// Store y co-ordinate of new live cell in sec_y
					s++;		// Incrementing index for sec_x and sec_y
				}
			}
			cout<<"X   Y"<<endl;
			for ( int i=0 ; i<s ; i++ )
			{
			cout<<sec_x[i]<<"   "<<sec_y[i]<<endl;
			}	

			for ( int i=0 ; i<index ; i++ )
			{
			nei_x[i] = 0;
			nei_y[i] = 0;
			}
			
			for ( int i=0 ; i<5 ; i++ )
			{
			cout<<"\n";
			}

		Start (draw , sec_x , sec_y , no_of_cells , nei_x , nei_y , 0 );		// Calling start function
	
	}
						
}	// Function ending
//=======================================DELETE X function================================================
//========================================================================================================
int replace_x ( int arr[] , int arr2[], int n , int x, int y )
{	
	int i=0 ; 
	
	// Loop for writing -1 in place of elements to be deleted from sec_x and sec_y
	while ( i<n )
	{	
		if ( arr[i] == x && arr2[i] == y)
		{
			arr[i] = -1;	
			arr2[i] = -1;
			break;
		} 
		i++;
		
	}	
	return n;		// n contains the total no of live cells remaining	
}
//=======================================DELETE Y function================================================
//========================================================================================================
int replace_y ( int arr[] , int arr2[], int n , int y, int x )
{	
	int i=0 ; 
	
	// Loop for writing -1 in place of elements to be deleted from sec_x and sec_y	
	while ( i<n )
	{
		if ( arr[i] == y && arr2[i] == x)
		{
			arr[i] = -1;	
			arr2[i] = -1;
			break;
		}
		i++;		
	}	
	return n;		// n contains the total no of live cells remaining
}
//=======================================DELETE Y function================================================
//========================================================================================================
int dlt ( int arr[] , int n , int no )	// Function for deleting -1 placed in sec_x and sec_y
{
	 int j = 0;

    for (int i=0; i < n; i++){
        for(int j=0;j<=i;j++){

            if(arr[i] == no){
                n--;
                for (int k=i; k<n; k++){
                    arr[k]=arr[k+1];
                }
                i--;     // you forgot to decrement i
            }
        }
    }

    return n;
}
//=======================================DRAWGRID function================================================
//========================================================================================================
void Drawgrid ( bool draw[20][20] )
{	// Function starting

	const int size=20;	// Declaration
	for(int i=0 ; i < size; i++)	// Loop running until size
	{
        for(int j=0 ; j < size; j++)	// Loop running until size
        {
            if(draw[j][i] == true)
            {
                cout << " 0 ";	// For users input, put 0 in the grid
            }
            else
            {
                cout << " . ";	// Otherwise display this character
            }
            
            if(j == size-1)	// In our grid if index reaches 20, next line
            {
                cout << endl;
            }
        }
    }

}	// Function ending
//=======================================Rules function===============================================
//========================================================================================================

