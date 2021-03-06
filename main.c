/*
    This program is about a cricket player management system. All in one player information holding system. Where user cam search player view all information and many more or an admin can enter a new player information and update information and delete information and may more.

    This project was done by:_
    Francis Rudra D Cruze
    francisrudra@gmail.com
*/
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

// function declaration
void welcome(); // welcome screen function
void title();   // title bar function
void titleRegistration();   // registration title bar function
void titleLogin();  // login title bar function
void masterLogin(); // master login ~ combine the viewer & admin function
void login();   // whole sign in & sign up function
void signUp();  // just sign up function
void signIn();  // just sign in function
void menuAdmin();   // admin menu function
void menuViewer();  // viewer menu function
void cricketerInformation();    // batsman information function
void saveInfo();    // Save into the file function
void viewAllInfo(); // View all information function
void searchInfo();  // search by name function
void editInfo();    // edit information function
void searchCountry();   // search by country function
void searchRole();  // search using the role
void removeInfo();  // remove data for a player function
void exitProgram(); // exit screen

// Global declaration
int okay, uCheck;
FILE *cricketerFile, *tempFile;
struct loginEntry
{
    char firstName[26], lastName[26], userName[15], password[15];
};

struct payerInformation
{
    char name[24],age[13],country[20],role[15],battingStyle[20],matchType[5];
    int iccRank, matchPlayed, innings, notOut,totalRun, heigestScore, balls, total4, total6, total50, total100, runGiven, wicketTaken, ballBowled;
    double over;
};

struct payerInformation crInfo;


int main(){
    int userChoice = 0;
    welcome();  // Welcome screen call
    loginRepeat:
    system("cls");
    masterLogin();  // master login user and admin function combine
    return 0;
}


/* ============  Welcome Screen  ============ */
void welcome(){
    printf("\n\n\n\n\n\n\n\t\t\t\t::::::::::::::::::::==================::::::::::::::::::::");
    printf("\n\t\t\t\t::\t\t\t WELCOME TO\t\t\t::");
    printf("\n\t\t\t\t::\t\t       Wiki-Cricketer \t\t\t::");
    printf("\n\t\t\t\t::::::::::::::::::::==================::::::::::::::::::::");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Make it Full Screen Please. Press any key to continue...");

    getch(); // use to hold the screen
    printf("\a");
    system("cls"); //use to clear the screen
}


/* ============  Title Bar  ============ */
void title(){
    printf("\n\n\t\t::::::::::::::::::::::::::::======================::::::::::::::::::::::::::::::::");
    printf("\n\t\t::\t\t\t\t Wiki-Cricketer \t\t\t\t::");
    printf("\n\t\t::::::::::::::::::::::::::::======================::::::::::::::::::::::::::::::::");
}



/* ============  Registration Title Bar  ============ */
void titleRegistration(){
    printf("\n\n\t\t:::::::::::::::::::::::::::::======================:::::::::::::::::::::::");
    printf("\n\t\t::\t\t\t Wiki-Cricketer ~ Registration \t\t\t::");
    printf("\n\t\t:::::::::::::::::::::::::::::======================:::::::::::::::::::::::");
}



/* ============  Login Title Bar  ============ */
void titleLogin(){
    // Title bar message
    printf("\n\n\t\t:::::::::::::::::::::::::::::======================:::::::::::::::::::::::");
    printf("\n\t\t::\t\t\t     Wiki-Cricketer ~ Login \t\t\t::");
    printf("\n\t\t:::::::::::::::::::::::::::::======================:::::::::::::::::::::::");
}


/* ============  Changing Console Position  ============ */
void positionXY(short x, short y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



/* ============  Sign Up  ============ */
void signUp (){

    // file declaration
    FILE *signUpIn;
    signUpIn = fopen("signUpIn.txt", "wb");
    struct loginEntry registerr;

    //printf("\n\n\n\n\t\t\t::::\tRegister into the system");

    // first name enter
    printf("\n\n\n\n\t\t\t::::\tEnter the first name : ");
    fflush(stdin);
    gets(registerr.firstName);
    strupr(registerr.firstName);

    // last name enter
    printf("\n\t\t\t::::\tEnter the last name : ");
    fflush(stdin);
    gets(registerr.lastName);
    strupr(registerr.lastName);

    // username enter
    printf("\n\t\t\t::::\tEnter the username : ");
    fflush(stdin);
    gets(&registerr.userName);

    // password enter
    printf("\n\t\t\t::::\tEnter the password : ");
    fflush(stdin);
    gets(registerr.password);

    // file write
    fwrite(&registerr, sizeof(struct loginEntry), 1, signUpIn);

    // file close
    fclose(signUpIn);

    printf("\n\n\n\t\t::::::::::::\tYour registration is successful\t\t::::::::::::\a\n\n\n\n\t\tNow login Can login\n\t\tPress any key to login...");
    getch();
    system("CLS");
    titleLogin();
    signIn();
}



/* ============  Sign In  ============ */
void signIn(){
    int check = 0;

    char userName[15], password[15];
    FILE* signUpIn;
    signUpIn = fopen("signUpIn.txt", "rb");
    struct loginEntry login;

    do{
        printf("\n\n\n\t\t\t\tUsername : ");
        fflush(stdin);
        scanf("%s", &userName);
        printf("\n\t\t\t\tPassword : ");
        fflush(stdin);
        scanf("%s", &password);

        // read form file
        fread(&login, sizeof(struct loginEntry), 1, signUpIn);
        // compare user input with file
        if(strcmp(userName, login.userName) == 0 && strcmp(password, login.password) == 0)
        {
            printf("\n\n\n\t\t::::::::::::\tYour login is successful\t::::::::::::\a\n\n\n\n\t\tPress any key to continue...\n\n\n");
            getch(); // to hold the screen
            system("cls");
            menuAdmin();
            break;
        }else
        {
            printf("\n\n\n\n\t\t\t::::::::::::\tThe username and password is incorrect\t::::::::::::");
            int checkYesNo = 0;
            printf("\n\n\t\t\tWhat you want to do ?\n\n\t\t\t1. Enter username & passowrd again ?\n\t\t\t2. Exit\n\n\t\t\tEnter your choice : ");
            fflush(stdin);
            scanf("%d", &checkYesNo);
            if(checkYesNo == 1)
            {
                check++;
            }else {
                exitProgram();  //  exit function call
            }
        }
    }while(check<=2);

    if(check>2)
    {
        printf("\n\n\n\t\t\t::::::::::::\tYou have cross the login limit. You can't login.\t::::::::::::");
        getch();
        system("cls");
    }

    fclose(signUpIn);
}


/* ============  Whole Login  ============ */
void login(){

    int userChoice;
    int checkYesNo = 0;
    title();    // title bar call
    printf("\n\n\n\n\t\t\tAdmin login & Registration portal\n\n\t\t\t::: 1 to login into the system\n\t\t\t::: 2 to registration into the system");

    printf("\n\n\n\t\t\tEnter your choice here : ");
    fflush(stdin);
    scanf("%d", &userChoice);

    if(userChoice == 1)
    {
        system("cls");
        titleLogin();   // login title bar call
        signIn();
    }else if(userChoice == 2)
    {
        loginRepeat:
        system("cls");
        titleRegistration();    // registration title bar call
        signUp();
    }else
    {
        printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid\t::::::::::::");
        printf("\n\n\t\t\tWhat you want to do ?\n\t\t\t1. Go to registration & password again ?\n\t\t\t2. Exit\n\n\t\t\tEnter your choice here : ");
        fflush(stdin);
        scanf("%d", &checkYesNo);
        if(checkYesNo == 1)
        {
            goto loginRepeat;
        }else {
            exitProgram();  //  exit function call
        }
    };
}


//#########################################    Master Login     #########################################
void masterLogin(){
    title();    // Title function
    int userChoice = 0;
    loginRepeat:
    printf("\n\n\n\t\t\tYou can login as a\n\n\t\t\t::: Enter 1 to Login in a Viewer\n\t\t\t::: Enter 2 to login a Admin\n\n\t\t\tEnter your choice here : ");
    fflush(stdin);
    scanf("%d", &userChoice);
    if(userChoice == 1)
    {
        menuViewer();    // user panel call
        printf("\a");
    }else if(userChoice == 2)
    {
        system("cls");
        printf("\a");
        login();    // login system call
    }
    else
    {
        system("cls");
        title();    // call title function
        printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid\t::::::::::::");
        printf("\n\n\t\t\tWhat you want to do ?\n\t\t\t1. Login in again\n\t\t\t2. Exit\n\n\t\t\tEnter your choice here : ");
        userChoice = 0;
        fflush(stdin);
        scanf("%d", &userChoice);
        if(userChoice == 1)
        {
            goto loginRepeat;
        }else {
            exitProgram();  //  exit function call
        }
    }
}


/* ============  Admin menu  ============ */
void menuAdmin(){
    adminMenu:
    system("cls");
    int choice = 0;
    title();    // title call
    printf("\n\n\n\t\t\t::: 1.  Enter New Cricketer Information");
    printf("\n\t\t\t::: 2.  Update Cricketer Information");
    printf("\n\t\t\t::: 3.  Search Cricketer information");
    printf("\n\t\t\t::: 4.  View all Players information");
    printf("\n\t\t\t::: 5.  Delete Players information");
    printf("\n\t\t\t::: 6.  Back to the main menu");
    printf("\n\t\t\t::: 7.  Go to the user panel");
    printf("\n\t\t\t::: 8.  Remove Whole Database");
    printf("\n\t\t\t::: 9.  Exit");
    printf("\n\n\n\t\t\t::: Enter what you want to do! :  ");
    fflush(stdin);
    scanf("%d", &choice);
    system("cls");

    switch(choice)
    {
        case 1:
            printf("Enter New Cricketer Information");
            cricketerInformation();   // add player information call
            break;
        case 2:
            editInfo(); // update cricketer information
            break;
        case 3:
            searchInfo();    // search information by name:
            break;
        case 4:
            title();    // title bar call
            printf("\n\n\n\t\t\t================ View All Cricketer Information ================\n\n");
            printf("View all Players information");
            viewAllInfo();  // view function
            goto adminMenu;
            break;
        case 5:
            removeInfo();   // REMOVE PLAYER INFORMATION
            break;
        case 6:
            title();
            masterLogin();  // master login panel function
            break;
        case 7:
            menuViewer();    // user panel function
            break;
        case 8:
            remove("playerInformation.txt");
            printf("\n\n\n\t\t\t================ Whole Database Remove Successful ================\n\n");
            getch();
            menuAdmin();
        case 9:
            exitProgram();  //  exit function call
            break;
            getch();
        default:
            choice = 0;
            system("cls");
            title();    // title bar call
            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid\t::::::::::::");
            printf("\n\n\t\t\tWhat you want to do ?\n\t\t\t1. Input again ?\n\t\t\t2. Exit\n\n\t\t\tEnter your choice here : ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                goto adminMenu;
            }else
            {
                exitProgram();  //  exit function call
            }
    }
}



/* ============  Viewer Menu  ============ */
void menuViewer(){
    int choice = 0;
    system("cls");
    title();    // title call
    printf("\n\n\n\t\t\t::: 1.  View all Player Information");
    printf("\n\t\t\t::: 2.  Search player by name");
    printf("\n\t\t\t::: 3.  View the various statistics of a cricketer");
    printf("\n\t\t\t::: 4.  View country wise player statistics");
    printf("\n\t\t\t::: 5.  Go to admin panel");
    printf("\n\t\t\t::: 6.  Back to the main menu");
    printf("\n\t\t\t::: 7.  Exit");
    printf("\n\n\n\t\t\t::: Enter what you want to do! :  ");
    fflush(stdin);
    scanf("%d", &choice);
    system("cls");
    switch(choice)
    {
        case 1:
            viewAllInfo();   // view player information call
            menuViewer();
            break;
        case 2:
            searchInfo();   // search information by name function
            break;
        case 3:
            searchRole();   // search information by role
            break;
        case 4:
            searchCountry();    // country search
            break;
        case 5:
            login();   // admin login function call
            break;
        case 6:
            masterLogin();    // login function call
            break;
        case 7:
            exitProgram();  //  exit function call
            break;
            getch();
        default:
            choice = 0;
            system("cls");
            title();    // title bar call
            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid\t::::::::::::");
            printf("\n\n\t\t\tWhat you want to do ?\n\t\t\t1. Input again ?\n\t\t\t2. Exit\n\n\t\t\tEnter your choice here : ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                menuViewer();   // call the same function ~ means userpannel function
            }else
            {
                exitProgram();  //  exit function call
            }
    }
}



/* ============  Input Information  ============ */
void cricketerInformation(){
    system("cls");
    title();    // title bar call
    printf("\n\n\n\t\t\t================ Add Batsman/Bowler Information ================\n\n");
    // players name input form user
    printf("\n\n\t\tPlayer Name\t\t:  ");
    fflush(stdin);
    gets(crInfo.name);
    strupr(crInfo.name);

    // players age input form user
    printf("\t\tPlayer Age (DD-MM-YEAR)\t:  ");
    fflush(stdin);
    gets(crInfo.age);

    // player country input form user
    printf("\t\tPlayer Country\t\t:  ");
    fflush(stdin);
    gets(crInfo.country);
    strupr(crInfo.country);

    // ICC ranking
    printf("\t\tICC Ranking\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.iccRank);

    // match type
    printf("\t\tMatch Type\t\t:  ");
    fflush(stdin);
    gets(crInfo.matchType);

    // match played
    printf("\t\tMatch Played\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.matchPlayed);

    // innings played
    printf("\t\tInnings Played\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.innings);

    // player role
    printf("\t\tPlayer Role\t\t:  Batsman//Bowler//AllRounder : ");
    fflush(stdin);
    gets(crInfo.role);
    strupr(crInfo.role);

    printf("\n\t\tIf you player is a batsman then give '0' of\nall bowler information, however if your player is a \nall rounder then input both otherwise do opposite.\n\n");

    // batting Style role
    printf("\t\tBatting Style\t\t:  ");
    fflush(stdin);
    gets(crInfo.battingStyle);

    // total not-out
    printf("\t\tTotal Not Out\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.notOut);

    // total run
    printf("\t\tTotal Run\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.totalRun);

    // highest score
    printf("\t\tHighest Score\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.heigestScore);

    // Over score
    printf("\n\t\tOver / balls faced ~ you can enter via 2 way\t:  ");
    printf("\n\t\t\t1. Over Faced\n\t\t\t2. Total Balled Faced\n\t\tEnter your choice here  :  ");
    overRepeat:
    uCheck = 0;
    fflush(stdin);
    scanf("%d", &uCheck);
    if(uCheck == 1)
    {
        printf("\t\tOver Played\t\t:  ");
        double fractional, integer; // fractional number (30.5) it count '30' ~ integer count '.5' value
        fflush(stdin);
        scanf("%lf", &crInfo.over);

        // over counting system
        fractional = modf(crInfo.over, &integer);
        int firstHalf = (integer * 6);
        int pointValue = (fractional * 10);

        // store over a balls
        crInfo.balls = (firstHalf + pointValue);
    }else if(uCheck == 2)
    {
        printf("\t\tBalls Played\t\t: ");
        fflush(stdin);
        scanf("%d", &crInfo.balls);
    }else
    {
        printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid\t::::::::::::");
        printf("\n\n\t\t\tWhat you want to do ?\n\t\t\t1. Input again ?\n\t\t\t2. Exit\n\t\tEnter your choice here : ");
        fflush(stdin);
        scanf("%d", &uCheck);
        if(uCheck == 1)
        {
            goto overRepeat;
        }else
        {
            exitProgram();  //  exit function call
        }
    }

    // total 4s form user
    printf("\t\tTotal 4s\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.total4);

    // total 6s form user
    printf("\t\tTotal 6s\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.total6);

    // total 50s form user
    printf("\t\tTotal 50\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.total50);

    // total 100s form user
    printf("\t\tTotal 100\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.total100);

    printf("\n=====  Bowlers Info  =====\n");

    // total run given
    printf("\t\tTotal run given\t\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.runGiven);

    // total wicket taken
    printf("\t\tTotal wicket taken\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.wicketTaken);

    // total ball bowled
    printf("\t\tTotal ball bowled\t:  ");
    fflush(stdin);
    scanf("%d", &crInfo.ballBowled);


    saveInfo(crInfo, cricketerFile);    // save in file

    moreInforAdd:
        printf("\n\n\t\tDo you want to add another player information [1 = yes/2 = no] :  ");
        fflush(stdin);
        scanf("%d", &okay);
        if(okay == 1)
        {
            cricketerInformation();
        }else if(okay == 2)
        {
            printf("\n\n\t\tThank you :) :)...\n\t\tNow back to the main menu : ");
            getch();
            menuAdmin();
        }else
        {
            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t::::::::::::");
            goto moreInforAdd;
        }
}


/* ============  Save into File  ============ */
void saveInfo(struct payerInformation crInfo, FILE *cricketerFile){
    cricketerFile = fopen("playerInformation.txt","a");
    fwrite(&crInfo,sizeof(struct payerInformation),1,cricketerFile);
    if(fwrite !=0){
        printf("\a\n\n\n\t\t\t================ Information Successfully Saved ================\n\n");
    }else{
        printf("\a\n\n\n\t\t\t================ Something went wrong ================\n\n");
    }
    fclose(cricketerFile);
}



/* ============  View all information  ============ */
void viewAllInfo() {
    int rowCount = 1;
    system("cls");
    title();    // title bar call
    printf("\n\n\n\t\t\t================ View All Player Information ================\n\n");

    cricketerFile = fopen("playerInformation.txt", "r");    // open the file

    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        //  actual value shown
        printf("=================================================\n");
        printf("= :::::: \tBatting Information\t :::::: =\n");
        printf("=\t\t\t\t\t\t=\n");
        printf("=  Name\t\t\t:  ");
        printf("%s\t\t=\n", crInfo.name);
        printf("=  Country\t\t:  ");
        printf("%s\t\t=\n", crInfo.country);
        printf("=  Role\t\t\t:  ");
        printf("%s\t\t=\n", crInfo.role);
        printf("=  Match Played\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.matchPlayed);
        printf("=  Innings\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.innings);
        printf("=  Total Runs\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.totalRun);
        printf("=  Batting Average\t:  ");

        if(crInfo.totalRun==0 && crInfo.innings==0 && crInfo.notOut==0)
            printf("0.00\t\t=\n");
        else
        {
            float batAvg = crInfo.totalRun / (crInfo.innings - crInfo.notOut);
            printf("%.2f%\t\t\t=\n", batAvg);
        }

        printf("=  Strike Rate\t\t:  ");
        float batStrike = (crInfo.totalRun * 100)/crInfo.balls;
        printf("%.2f\t\t=\n", batStrike);

        printf("\n= :::::: \tBowling Information\t :::::: =\n\n");

        printf("=  ICC Ranking\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.iccRank);
        printf("=  Run Given\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.runGiven);
        printf("=  Wicket Taken\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.wicketTaken);
        printf("=  Ball Bowled\t\t:  ");
        printf("%d\t\t\t=\n", crInfo.ballBowled);
        printf("=  Bowling Avg\t\t:  ");

        if(crInfo.runGiven==0 && crInfo.wicketTaken==0)
            printf("0.00\t\t\t=\n");
        else
        {
            float bowlingAvg = crInfo.runGiven / crInfo.wicketTaken;
            printf("%.2f\t\t=\n", bowlingAvg);
        }

        printf("=  Bowling Strike Rate\t:  ");

        if(crInfo.ballBowled==0 && crInfo.wicketTaken==0)
            printf("0.00\t\t=\n");
        else
        {
            float bowlingStrike = crInfo.ballBowled / crInfo.wicketTaken;
            printf("%.2f\t\t=\n", bowlingStrike);
        }

        printf("=  Economy Rate\t\t:  ");

        if(crInfo.runGiven==0 && crInfo.ballBowled==0)
            printf("0.00\t\t=\n");
        else
        {
            float bowlingEconomy = (crInfo.runGiven * 6) / crInfo.ballBowled;
            printf("%.2f\t\t\t=\n", bowlingEconomy);
        }
        printf("=================================================\n\n\n");
    }

    fclose(cricketerFile);  // close the file
    getch();
}



/* ============  Search information by name  ============ */
void searchInfo(){
    char searchName[24];
    int rowCount = 1;
    system("cls");
    title();
    cricketerFile = fopen("playerInformation.txt", "r");    // open the file
    printf("\n\n\t\t======================\tSearch Player By name\t======================");
    printf("\n\n\t\t\tEnter the player name :  ");
    fflush(stdin);
    gets(searchName);
    int found = 0;
    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        //printf("The name is: %s\n", &crInfo.name);
        if(strcmp(strupr(searchName), crInfo.name) == 0)
        {
            found = 1;
            printf("\n\n=================================================\n");
            printf("= :::::: \tBatting Information\t :::::: =\n");
            printf("=\t\t\t\t\t\t=\n");
            printf("=  Name\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.name);
            printf("=  Country\t\t:  ");
            printf("%s\t\t=\n", crInfo.country);
            printf("=  Role\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.role);
            printf("=  Match Played\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.matchPlayed);
            printf("=  Innings\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.innings);
            printf("=  Total Runs\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.totalRun);
            printf("=  Batting Average\t:  ");

            if(crInfo.totalRun==0 && crInfo.innings==0 && crInfo.notOut==0)
                printf("0.00\t\t=\n");
            else
            {
                float batAvg = crInfo.totalRun / (crInfo.innings - crInfo.notOut);
                printf("%.2f%\t\t\t=\n", batAvg);
            }

            printf("=  Strike Rate\t\t:  ");
            float batStrike = (crInfo.totalRun * 100)/crInfo.balls;
            printf("%.2f\t\t=\n", batStrike);

            printf("\n= :::::: \tBowling Information\t :::::: =\n\n");

            printf("=  ICC Ranking\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.iccRank);
            printf("=  Run Given\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.runGiven);
            printf("=  Wicket Taken\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.wicketTaken);
            printf("=  Ball Bowled\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.ballBowled);
            printf("=  Bowling Avg\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t\t=\n");
            else
            {
                float bowlingAvg = crInfo.runGiven / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingAvg);
            }

            printf("=  Bowling Strike Rate\t:  ");

            if(crInfo.ballBowled==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingStrike = crInfo.ballBowled / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingStrike);
            }

            printf("=  Economy Rate\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.ballBowled==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingEconomy = (crInfo.runGiven * 6) / crInfo.ballBowled;
                printf("%.2f\t\t\t=\n", bowlingEconomy);
            }
            printf("=================================================\n\n\n");
        }
    }
    if(found == 0)
    {
        printf("\n\n\n\n\t\t\t::::::::::::\tFile Not Found\t::::::::::::");
    }
    fclose(cricketerFile);  // close the file

    searchPlayer:
    getch();
    printf("\n\n\n\t\t\t================\tDO you want to search agina [ 1 = Yes & 2 = No] ? : ");
    fflush(stdin);
    scanf("%d", &okay);
    if(okay == 1)
       {
            searchInfo();
       }else if(okay == 2)
       {
            printf("\n\n\t\tThank you :) :)...\n\t\tNow back to the main menu : ");
            getch();
            menuViewer();
       }else
       {
            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t::::::::::::");
            goto searchPlayer;
       }
}


/* ============  Search information by Country  ============ */
void searchCountry() {
    char searchCountryy[24];
    int rowCount = 1;
    system("cls");
    title();
    cricketerFile = fopen("playerInformation.txt", "r");    // open the file
    printf("\n\n\t\t======================\tSearch Player By Country\t======================");
    printf("\n\n\t\t\tEnter the player country :  ");
    fflush(stdin);
    gets(searchCountryy);

    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        if(strcmpi(strupr(searchCountryy), crInfo.country) == 0)
        {
            printf("\n\n=================================================\n");
            printf("= :::::: \tBatting Information\t :::::: =\n");
            printf("=\t\t\t\t\t\t=\n");
            printf("=  Name\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.name);
            printf("=  Country\t\t:  ");
            printf("%s\t\t=\n", crInfo.country);
            printf("=  Role\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.role);
            printf("=  Match Played\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.matchPlayed);
            printf("=  Innings\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.innings);
            printf("=  Total Runs\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.totalRun);
            printf("=  Batting Average\t:  ");

            if(crInfo.totalRun==0 && crInfo.innings==0 && crInfo.notOut==0)
                printf("0.00\t\t=\n");
            else
            {
                float batAvg = crInfo.totalRun / (crInfo.innings - crInfo.notOut);
                printf("%.2f%\t\t\t=\n", batAvg);
            }

            printf("=  Strike Rate\t\t:  ");
            float batStrike = (crInfo.totalRun * 100)/crInfo.balls;
            printf("%.2f\t\t=\n", batStrike);

            printf("\n= :::::: \tBowling Information\t :::::: =\n\n");

            printf("=  ICC Ranking\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.iccRank);
            printf("=  Run Given\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.runGiven);
            printf("=  Wicket Taken\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.wicketTaken);
            printf("=  Ball Bowled\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.ballBowled);
            printf("=  Bowling Avg\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t\t=\n");
            else
            {
                float bowlingAvg = crInfo.runGiven / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingAvg);
            }

            printf("=  Bowling Strike Rate\t:  ");

            if(crInfo.ballBowled==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingStrike = crInfo.ballBowled / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingStrike);
            }

            printf("=  Economy Rate\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.ballBowled==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingEconomy = (crInfo.runGiven * 6) / crInfo.ballBowled;
                printf("%.2f\t\t\t=\n", bowlingEconomy);
            }
            printf("=================================================\n\n\n");
        }
    }
    fclose(cricketerFile);
    repeatCountry:
    uCheck = 0;
    getch();
    printf("\n\t\t\tWant to search another ? \n\t\t\t1. yes\n\t\t\t2. No\n\t\t\tEnter your choice here: ");
    fflush(stdin);
    scanf("%d", &uCheck);
    if(uCheck == 1)
    {
        searchCountry();    // call country function for another search
    }
    else if(uCheck == 2)
    {
        menuViewer();   // call viewer menu to back
    }
    else
    {
        printf("\n\t\t\t===== Your input is invalid Retype again: ");
        goto repeatCountry;
    }
}

/* ============  Search information by Role  ============ */
void searchRole() {
    char searchRolee[24];
    int rowCount = 1;
    system("cls");
    title();
    cricketerFile = fopen("playerInformation.txt", "r");    // open the file
    printf("\n\n\t\t======================\tSearch Player By Role ~ batting/bowling/allrounder\t======================");
    printf("\n\n\t\t\tEnter the player role :  ");
    fflush(stdin);
    gets(searchRolee);

    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        if(strcmpi(strupr(searchRolee), crInfo.role) == 0)
        {
            printf("\n\n=================================================\n");
            printf("= :::::: \tBatting Information\t :::::: =\n");
            printf("=\t\t\t\t\t\t=\n");
            printf("=  Name\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.name);
            printf("=  Country\t\t:  ");
            printf("%s\t\t=\n", crInfo.country);
            printf("=  Role\t\t\t:  ");
            printf("%s\t\t=\n", crInfo.role);
            printf("=  Match Played\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.matchPlayed);
            printf("=  Innings\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.innings);
            printf("=  Total Runs\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.totalRun);
            printf("=  Batting Average\t:  ");

            if(crInfo.totalRun==0 && crInfo.innings==0 && crInfo.notOut==0)
                printf("0.00\t\t=\n");
            else
            {
                float batAvg = crInfo.totalRun / (crInfo.innings - crInfo.notOut);
                printf("%.2f%\t\t\t=\n", batAvg);
            }

            printf("=  Strike Rate\t\t:  ");
            float batStrike = (crInfo.totalRun * 100)/crInfo.balls;
            printf("%.2f\t\t=\n", batStrike);

            printf("\n= :::::: \tBowling Information\t :::::: =\n\n");

            printf("=  ICC Ranking\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.iccRank);
            printf("=  Run Given\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.runGiven);
            printf("=  Wicket Taken\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.wicketTaken);
            printf("=  Ball Bowled\t\t:  ");
            printf("%d\t\t\t=\n", crInfo.ballBowled);
            printf("=  Bowling Avg\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t\t=\n");
            else
            {
                float bowlingAvg = crInfo.runGiven / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingAvg);
            }

            printf("=  Bowling Strike Rate\t:  ");

            if(crInfo.ballBowled==0 && crInfo.wicketTaken==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingStrike = crInfo.ballBowled / crInfo.wicketTaken;
                printf("%.2f\t\t=\n", bowlingStrike);
            }

            printf("=  Economy Rate\t\t:  ");

            if(crInfo.runGiven==0 && crInfo.ballBowled==0)
                printf("0.00\t\t=\n");
            else
            {
                float bowlingEconomy = (crInfo.runGiven * 6) / crInfo.ballBowled;
                printf("%.2f\t\t\t=\n", bowlingEconomy);
            }
            printf("=================================================\n\n\n");
        }
    }
    fclose(cricketerFile);
    getch();
    repeatCountry:
    uCheck = 0;
    printf("\n\n\n\n\n\t\t\tWant to search another ? \n\t\t\t1. yes\n\t\t\t2. No\n\t\t\tEnter your choice here: ");
    fflush(stdin);
    scanf("%d", &uCheck);
    if(uCheck == 1)
    {
        searchCountry();    // call country function for another search
    }
    else if(uCheck == 2)
    {
        menuViewer();   // call viwer menu to back
    }
    else
    {
        printf("\n\t\t\t===== Your input is invalid Retype again: ");
        goto repeatCountry;
    }
}


/* ============  Edit Info  ============ */
void editInfo(){
    char searchName[24];
    int updateRun, ballsPlayed, runGivenn, wicketTakenn, ballBowleddd;
    system("cls");
    title();    // call title function

    printf("\n\n\t\t\t=================Update Player Information=================");

    cricketerFile = fopen("playerInformation.txt", "r+");    // open the file

    printf("\n\n\t\t======================\tSearch Player By name\t======================");
    printf("\n\n\t\t\tEnter the player name :  ");
    fflush(stdin);
    gets(searchName);
    int found = 0;
    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        if(strcmpi(crInfo.name,strupr(searchName)) == 0)
        {
            printf("\n\n\t\t\t================= Player Found =================");
            found = 1;
            editAnother:
            printf("\n\n\t\tWhat you want to do : ");
            printf("\n\t\t::1. Edit General Information");
            printf("\n\t\t::2. Edit Match Information");
            printf("\n\t\t::3. Back to main menu");
            printf("\n\t\t::4. Exit");
            printf("\n\n\t\t::Enter Your Choice Here : ");

            uCheck = 0;
            fflush(stdin);
            scanf("%d", &uCheck);
            switch(uCheck)
            {
                case 1:
                    system("cls");
                    title();    // call the title function
                    generalEdit:
                    printf("\n\n\n\t\t\t=================Edit General Information=================\n\n");
                    printf("\n\t\t::1. Edit Name");
                    printf("\n\t\t::2. Edit Country");
                    printf("\n\t\t::3. Edit Ranking");
                    printf("\n\t\t::Enter Your Choice Here : ");
                    uCheck = 0;
                    fflush(stdin);
                    scanf("%d", &uCheck);
                    switch(uCheck)
                    {
                        case 1:
                            printf("\n\t\tEnter new name: ");
                            fflush(stdin);
                            gets(crInfo.name);
                            strupr(crInfo.name);
                            break;
                        case 2:
                            printf("\n\t\tEnter new Country: ");
                            fflush(stdin);
                            gets(crInfo.country);
                            break;
                        case 3:
                            printf("\n\t\tEnter new Ranking: ");
                            fflush(stdin);
                            scanf("%d", &crInfo.iccRank);
                            break;
                        default:
                            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t::::::::::::");
                            goto generalEdit;
                    }
                    break;
                case 2:
                    updateMatch:
                    crInfo.matchPlayed += 1;
                    printf("\n\n\t\t\t================= Edit/Update Match Information =================");
                    printf("\n\t\tThe player is Play the innings or not..\n\t\t1. Played\n\t\t2. Not Played\n\t\tEnter your choice here : ");
                    uCheck = 0;
                    inningss:
                    fflush(stdin);
                    scanf("%d", &uCheck);
                    if(uCheck == 1)
                    {
                        crInfo.innings += 1;
                        printf("\t\tThe player is out or not..\n\t\t1. Not Out\n\t\t2. Out\n\t\tEnter your choice here : ");
                        uCheck = 0;
                        outNot:
                        fflush(stdin);
                        scanf("%d", &uCheck);
                        if(uCheck == 1)
                        {
                            crInfo.notOut += 1;
                            printf("\t\t::Match Run: ");
                            fflush(stdin);
                            scanf("%d", &updateRun);
                            crInfo.totalRun += updateRun;
                            printf("\t\tBalled Played: ");
                            scanf("%d", &ballsPlayed);
                            crInfo.balls += ballsPlayed;
                        }
                        else if(uCheck == 2)
                        {

                        }else
                        {
                            printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t:::::::::::: ");
                            goto outNot;
                        }
                        // Bowler information update

                        printf("\n\t\t\tBowler Information Update.. if your player is a bowler or allrounder\n");
                        printf("\t\tTotal run given: ");
                    }
                    else if(uCheck == 2)
                    {

                    }else
                    {
                        printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t:::::::::::: ");
                        goto inningss;
                    }
                    bowlingUpdate:
                    printf("\n\n\t\t\t::::::::::::\tBowling Information Update\t:::::::::::: ");
                    printf("\n\t\tThe player is Play the bowling innings or not..\n\t\t1. Played\n\t\t2. Not Played\n\t\tEnter your choice here : ");
                    uCheck = 0;
                    fflush(stdin);
                    scanf("%d", &uCheck);
                    if(uCheck == 1)
                    {
                        printf("\t\tRun Given: ");
                        scanf("%d", &runGivenn);
                        crInfo.runGiven += runGivenn;
                        printf("\t\tWicket Taken: ");
                        scanf("%d", &wicketTakenn);
                        crInfo.wicketTaken += wicketTakenn;
                        printf("\t\tBall Bowled: ");
                        scanf("%d", &ballBowleddd);
                        crInfo.ballBowled += ballBowleddd;
                    }else if(uCheck == 2)
                    {

                    }else
                    {
                        printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t::::::::::::");
                        goto bowlingUpdate;
                    }
                    break;
                case 3:
                    system("cls");
                    menuAdmin();
                    break;
                case 4:
                    exitProgram();  //  exit function call
                    break;
                default:
                    printf("\n\n\n\n\t\t\t::::::::::::\tYour input is invalid - Input again\t::::::::::::");
                    goto editAnother;
                    break;
            }
            printf("\n\n\n\n\t\t\t::::::::::::\tInformation Update Succesful\t::::::::::::");
            fseek(cricketerFile,-sizeof(crInfo),SEEK_CUR);
            fwrite(&crInfo,sizeof(struct payerInformation),1,cricketerFile);
            fclose(cricketerFile);
            repeatCountry:
            uCheck = 0;
            printf("\n\n\n\n\n\t\t\tWant to Edit Again ? \n\t\t\t1. yes\n\t\t\t2. Back to main menu\n\t\t\tEnter your choice here: ");
            fflush(stdin);
            scanf("%d", &uCheck);
            if(uCheck == 1)
            {
                editInfo();    // call country function for another search
            }
            else if(uCheck == 2)
            {
                menuAdmin();   // call viwer menu to back
            }
            else
            {
                printf("\n\t\t\t===== Your input is invalid Retype again: ");
                goto repeatCountry;
            }
        }

    }
}


/* ============  Remove information  ============ */
void removeInfo() {
    char searchName[24];
    system("cls");
    title();    // call title function

    printf("\n\n\t\t\t================= Delete/Remove Player Information =================");

    cricketerFile = fopen("playerInformation.txt", "r+");    // open the original file
    tempFile = fopen("temporaryCrInfo.txt", "w");

    printf("\n\n\t\t======================\tSearch Player By name\t======================");
    printf("\n\n\t\t\tEnter the player name :  ");
    fflush(stdin);
    gets(searchName);
    int flag = 0;
    while(fread(&crInfo,sizeof(struct payerInformation),1,cricketerFile))
    {
        if(strcmpi(crInfo.name, searchName) != 0)
        {
            if(crInfo.name!=searchName)
            {
                fwrite(&crInfo, sizeof(struct payerInformation), 1, tempFile);
                flag = 1;
            }
        }
    }
    fclose(cricketerFile);
    fclose(tempFile);
    remove("playerInformation.txt");
    rename("temporaryCrInfo.txt", "playerInformation.txt");
    if(flag==1)
        printf("\n\n\t\t======================\tRecode Delete Successful\t======================");
    else
        printf("\n\n\t\t======================\tRecode Now Found\t======================");
    getch();
    repeatDelete:
        uCheck = 0;
        printf("\n\n\n\n\n\t\t\tWant to Delete Another ? \n\t\t\t1. yes\n\t\t\t2. Back to main menu\n\t\t\tEnter your choice here: ");
        fflush(stdin);
        scanf("%d", &uCheck);
        if(uCheck == 1)
        {
            removeInfo();    // call country function for another search
        }
        else if(uCheck == 2)
        {
            menuAdmin();   // call viwer menu to back
        }
        else
        {
            printf("\n\t\t\t===== Your input is invalid Retype again: ");
            goto repeatDelete;
        }
}



/* ============  RExit Program   ============ */
void exitProgram() {
    system("cls");
    title();    // call title function
    printf("\n\n\n\n\n\t\t\tTHANKS FOR VISITING WIKI-CRICKETER :) :)\n\n\n\n\n\n\n\n");
    getch();
    exit(0);
}






