//Programmer: Ryan Vasquez
//Date: September 22, 2013
//Class: CS53 Section F
//Purpose: This is program will act as a slot machine for Moe's homemade
//slot machine. It can transfer money and calculate wins and losses
//for the user
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int Game_balance = 0;//Initializes Game_balance to 0 so that the user does
    //not get junk when he/shee checks thier balance for the first time.
    int Bankk_balance = 0;
    int Transfunds;
    int Net_Change = 0;
    const int TWOMATCH = 1;
    const int THREEMATCH = 30;
    const int NOMATCH = -5;
    int Menu_choice;
    int Rand_int1;
    int Rand_int2;
    int Rand_int3;
    int Num_games;
    srand(time(NULL));
    //------_This section welcomes the user to the program----//
    cout<<"Welcome to Moe's homemade slot machine!"<<endl;
    cout<<"Step right up and try your luck!"<<endl;
    cout<<"      .-------."<<endl;
    cout<<"   oO{-JACKPOT-}Oo"<<endl;
    cout<<"   .=============. __"<<endl;
    cout<<"   | [a] [X] [o] |(  )"<<endl;
    cout<<"   | [$] [$] [$] | ||"<<endl;
    cout<<"   | [X] [o] [$] | ||"<<endl;
    cout<<"   |             |_||"<<endl;
    cout<<"   | $$$ ::::::: |--'"<<endl;
    cout<<"   |      __ === |"<<endl;
    cout<<"   |_____/__\\____|"<<endl;
    cout<<"  /###############\\"<<endl;
    cout<<" /#################\\"<<endl;
    cout<<"|#JGS###############|"<<endl;
    Bankk_balance = rand()%801 + 200; //This line of program seeds the intial
    //bankk balance between $200-$1000 for the user
    do
    {
      if(Bankk_balance >=5)//This logic statement checks if the user has more
      //than 5 dollars in his bankk account
      {
        cout<<"---------------------------------------"<<endl;
        cout<<"             Options                  |"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Check Bankk balance                |"<<endl;
        cout<<"2. Transfer funds to game             |"<<endl;
        cout<<"3. Play                               |"<<endl;
        cout<<"4. Leave (cash out)                   |"<<endl;
        cout<<"5. Play Multiple Games -- Extra Credit|"<<endl;
        cout<<"---------------------------------------"<<endl;
      }
      else if (Game_balance < 5 && Bankk_balance >= 5)//This logic line will
      //take away the option to play if he has no money is his game balance
      //but he has money in his bankk balance.
      {
        cout<<"---------------------------------------"<<endl;
        cout<<"             Options                  |"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Check Bankk balance                |"<<endl;
        cout<<"2. Transfer funds to game             |"<<endl;
        cout<<"4. Leave (cash out)                   |"<<endl;
        cout<<"---------------------------------------"<<endl;
      }
      else //If the user does not have any money in either account he is given
      //no option but to leave or continue to check his balance.
      {
        cout<<"---------------------------------------"<<endl;
        cout<<"             Options                  |"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Check Bankk balance                |"<<endl;
        cout<<"4. Leave (cash out)                   |"<<endl;
        cout<<"---------------------------------------"<<endl;
      }
      cout<<"Please enter your menu choice now: "; //Prompts the user for a
      //menu choice
      cin>>Menu_choice;
      switch(Menu_choice)
      {
        case 1: //Will display the bankk balance and the game balance
          cout<<" \n Your Bankk Balance is $"<< Bankk_balance<<endl;
          cout<<" \n Your Game Balance is $"<< Game_balance<<endl;
          break;
        case 2: //This will transfer funds from the bank to the game
          cout<<" \n Please enter the amount of money you would like"<<endl;
          cout<<"transfer to the game. $";
          cin>>Transfunds;
          Game_balance = Game_balance + Transfunds; //This line adds the transfer
          //transfer amount to the game balance
          Bankk_balance = Bankk_balance - Transfunds; //This line subtracts the
          //transfer amount form the bankk balance
          cout<<"Your transfer was successful."<<endl; //Confirms a successful
          //transaction
          break;
        case 3:
          cout<<"Get ready to play!"<<endl<<endl;
          Rand_int1 = rand()%4 + 1;//This will generate the random number
          Rand_int2 = rand()%4 + 1;//This will generate the random number
          Rand_int3 = rand()%4 + 1;//This will generate the random number
          //The following section will output the results of the three
          //random numbers to the user in a user-friendly fasion.
          cout<<"_______________________"<<endl;
          cout<<"|                     |"<<endl;
          cout<<"|    "<<Rand_int1<<"  |  "<<Rand_int2<<"  |  "<<Rand_int3<<" "
          <<"   |"<<endl;
          cout<<"|                     |"<<endl;
          cout<<"-----------------------"<<endl<<endl;
          if( Rand_int1 == Rand_int2 && Rand_int2 == Rand_int3)//This logic
              //statement will check if three of the random number match and
              //add thirty dollars the game balance for the user.
          {
            Game_balance += THREEMATCH;
            cout<<"You won $30!!!!"<<endl;

          }
          else if ( Rand_int1 == Rand_int2 || Rand_int1 == Rand_int3 ||
                Rand_int3 == Rand_int2)//This logic statement will check if two
                //of the random numbers match and will add 1 dollar to the user
                //game balance.
          {
            Game_balance += TWOMATCH;
            cout<<"You won $1, congrats!"<<endl;
          }
          else
          {
            if(Game_balance < 5 && Bankk_balance >= 5)//This logic line
                //will check if the user has money in his bankk account but not
                //in his game balance and will prompt him to transfer more
                //money.
            {
              cout<<"Please transfer more money into the your"<<endl;
              cout<<"game account, you don't have enough money to "<<endl;
              cout<<"pay for this loss"<<endl;
            }
            else if(Game_balance < 5 && Bankk_balance < 5)
             //This logic line will prompt the user to leave the game if he
              //has no money in either account
            {
              cout<<"Please leave the game, you are all out of ";
              cout<<"money"<<endl;
            }
            else
            {
              Game_balance += NOMATCH;
              cout<<"You lost! Try again!"<<endl;
            }
          }
          break;
        case 4:
            cout<<"Please play come another day goodbye"<<endl;
            cout<<" \n Your Bankk Balance is $"<< Bankk_balance<<endl;
            cout<<" \n Your Game Balance is $"<< Game_balance<<endl;
            break;
        case 5:
            cout<<"How many games would you like to cycle through?"<<endl;
            cin>>Num_games;
            for(int i = 0; i < Num_games; i++) //The for loop will count
            //and repeat the play action until it reaches the number of
            //repetions the user input or until the user runs out of money
            //, whichever occurs first.
            {
              Rand_int1 = rand()%4 + 1;//This will generate the random number
              Rand_int2 = rand()%4 + 1;//This will generate the random number
              Rand_int3 = rand()%4 + 1;//This will generate the random number
              if(Rand_int1 == Rand_int2 && Rand_int2 == Rand_int3)//This logic
              //statement will check if three of the random number match and
              //add thirty dollars the game balance for the user.
              {
                Game_balance += THREEMATCH;
                Net_Change +=THREEMATCH;
              }
              else if ( Rand_int1 == Rand_int2 || Rand_int1 == Rand_int3 ||
                Rand_int3 == Rand_int2)//This logic statement will check if two
                //of the random numbers match and will add 1 dollar to the user
                //game balance.
              {
                Game_balance += TWOMATCH;
                Net_Change += TWOMATCH;
              }
              else
              {
                if(Game_balance < 5 && Bankk_balance >= 5)//This logic line
                //will check if the user has money in his bankk account but not
                //in his game balance and will prompt him to transfer more
                //money.
                {
                  cout<<"Please transfer more money into the your"<<endl;
                  cout<<"game account, you don't have enough money to "<<endl;
                  cout<<"pay for this loss"<<endl;
                  i = Num_games; //This line will cause the for loop to exit
                }
                else if(Game_balance < 5 && Bankk_balance < 5)
                //This logic line will prompt the user to leave the game if he
                //has no money in either account
                {
                  cout<<"Please leave the game, you are all out of ";
                  cout<<"money"<<endl;
                  i = Num_games; //This line will cause the for loop to exit
                }
                else
                {
                  Game_balance += NOMATCH;
                  Net_Change += NOMATCH;
                }
              }
            }
          cout<<"Your net account change is $"<<Net_Change<<endl;
          cout<<"Your game balance is now $"<<Game_balance<<endl;
          break;
        default:
            cout<<"Please Enter a valid menu choice"<<endl;
            break;
      }
    }while( Menu_choice != 4); //This logic statement will make the loop
    //continue until the user has chosen to leave the game.
}
