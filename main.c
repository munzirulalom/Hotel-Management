#include<stdio.h>
#include<conio.h>
struct user
{
    char name[100];
    char username[50];
    char email[50];
    char password[100];
    char nid[50];
    char address[100];
    char nationality[20];
};
struct room
{
    int no;
    char name[50];
    char features[200];
    int type;
    int price;
};
struct food
{
    char name[50];
    char discreption[200];
    int price;
};
struct order
{
    char in_date[25];
    char out_date[25];
    int item_count;
    int adult_count;
    int children_count;
    int price;
};
struct payment
{
    int no;
    int code;
    char expire;
};

int thanks()
{
    printf("Thank You!\nYour Order is placed.");
    getch();
    user_menu();
}

//Card Payment Function
int card(int price)
{
    struct payment card;
    printf("Enter Card No\t\t: ");scanf("%d", &card.no);
    printf("Enter Card Expire Date\t: ");scanf("%s", &card.expire);
    printf("Enter CVC No\t\t: ");scanf("%d", &card.code);
    printf("Total Price is\t\t: %d", price);

    char c;
    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        printf("Payment Confirm..........");
        thanks();
    }
    else
        printf("Payment Deny..............");
}

//Mobile Banking Payment Function
int m_banking(int price)
{
    struct payment m_bank;

    printf("Enter Your Mobile Banking (Bkash/Rocket) Number: ");scanf("%d", &m_bank.no);
    printf("Enter Your PIN: ");scanf("%d", &m_bank.code);

    char c;
    printf("Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        printf("Payment Confirm..........\n");
        thanks();
    }
    else
        printf("Payment Deny..............\n");
}

//Payment Function
int payment(int price)
{
    system("CLS");
    int N;
    printf("1. Visa/Credit/MasterCard\n2. Bkash/Rocket\n3. Cash\n");
    printf("Enter Choice: ");scanf("%d", &N);

    switch(N)
    {
    case 1:
        card(price);
        break;
    case 2:
        m_banking(price);
        break;
    case 3:
        printf("Pay at Counter in Cash\n");
        break;
    default:
        printf("Error! Invalid Input..");
        getch();
        user_menu();
    }
}

//Order Function
int order(int a)
{
    system("CLS");
    if(a==1)
    {
        printf("Room Booking Function\n");
        struct order room;
        printf("Check ID Date(D-M-Y): ");scanf("%s", &room.in_date);
        printf("Check Out Date (D-M-Y): ");scanf("%s", &room.out_date);
        printf("How Many Rooms: ");scanf("%d", &room.item_count);
        printf("How Many Adults: ");scanf("%d", &room.adult_count);
        printf("How Many Children: ");scanf("%d", &room.children_count);

        system("CLS");
        printf("Please Re-Check Your Order And Confirm..\n");
        printf("Check IN Date\t: \t\t%s\n", room.in_date);
        printf("Check Out Date\t: \t\t%s\n", room.out_date);
        printf("Rooms\t\t: \t\t%d\n", room.item_count);
        printf("Adults\t\t: \t\t%d\n", room.adult_count);
        printf("Children\t: \t\t%d\n", room.children_count);

        char c;
        printf("To Confirm Your Order (Y/N): ");scanf("%s", &c);
        if(c=='Y')
        {
            payment(25640);
        }
        else
            printf("Order Deny..............");
        getch();
        room_menu();

    }
    else if(a==2)
    {
        printf("Food Order Function\n");
        payment(1200);
    }
    getch();
    user_menu();
}

//User Dinner Food List Fuunction
int dinner_food_list()
{
    system("CLS");
    printf("Dinner Food List");
    getch();
    order(2);
}

//User Snacks Food List Function
int snacks_food_list()
{
    system("CLS");
    printf("                     ######  ###    ##     ##       #####   ##   ##   ######    \n");
    printf("                    #        ## #   ##    ####     ##    #  ## ##    #          \n");
    printf("                     #####   ##  #  ##   ##  ##    ##       ###       #####     \n");
    printf("                          #  ##   # ##  ## ## ##   ##    #  ## ##          #    \n");
    printf("                    ######   ##    ### ##      ##   #####   ##   ##  ######     \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Berger          --  250 tk      ##\n" );
    printf("\t\t2.      Sandwich        --  180 tk      ##\n" );
    printf("\t\t3.      Beef Stick      --  350 tk      ##\n" );
    printf("\t\t4.      Nachos          --  200 tk      ##\n" );
    printf("\t\t5.      Sicilian Pizza  --  550 tk      ##\n" );
    printf("\t\t6.      Mango Juces     --  80  tk      ##\n" );
    printf("\t\t7.      Chicken Fry     --  450 tk      ##\n" );
    printf("\t\t8.      Water 1 Lt.     --  50  tk      ##\n" );
    printf("\t\t9.      Water 2 Lt.     --  95  tk      ##\n" );

    getch();
    order(2);
}

//User Lunch Food List Function
int lunch_food_list()
{
    system("CLS");
    printf("                    ##       ##   ##  ###    ##   #####   ##    ##  \n");
    printf("                    ##       ##   ##  ## #   ##  ##    #  ##    ##  \n");
    printf("                    ##       ##   ##  ##  #  ##  ##       ########  \n");
    printf("                    ##    #  ##   ##  ##   # ##  ##    #  ##    ##  \n");
    printf("                    ######    #####   ##    ###   #####   ##    ##  \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Rice        --      60  tk      ##\n" );
    printf("\t\t2.      Fried Rice  --      250 tk      ##\n" );
    printf("\t\t3.      Beef        --      360 tk      ##\n" );
    printf("\t\t4.      Mutton      --      450 tk      ##\n" );
    printf("\t\t5.      Pulses      --      40  tk      ##\n" );
    printf("\t\t6.      Kabab       --      160 tk      ##\n" );
    printf("\t\t7.      Fish        --      250 tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );
    printf("\t\t9.      Chicken     --      280 tk      ##\n" );
    getch();
    order(2);
}

//User Breakfast Food List Function
int breakfast_food_list()
{
    system("CLS");
    printf("            #####   #####   #####      ##       #####   ##   ##  #####     ##      #####   ######## \n");
    printf("            ##  ##  ##  ##  ##        ####     ##    #  ## ##    ##       ####    #           ##    \n");
    printf("            #####   #####   #####    ##  ##    ##       ###      #####   ##  ##    #####      ##    \n");
    printf("            ##  ##  ## ##   ##      ## ## ##   ##    #  ## ##    ##     ## ## ##        #     ##    \n");
    printf("            #####   ##  ##  #####  ##      ##   #####   ##   ##  ##    ##      ##  #####      ##    \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Bread       --      100 tk      ##\n" );
    printf("\t\t2.      Eggs        --      60  tk      ##\n" );
    printf("\t\t3.      Coffee      --      200 tk      ##\n" );
    printf("\t\t4.      Green Tea   --      150 tk      ##\n" );
    printf("\t\t5.      Normal Tea  --      80  tk      ##\n" );
    printf("\t\t6.      Nuts        --      500 tk      ##\n" );
    printf("\t\t7.      Nun Bread   --      70  tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );

    getch();
    order(2);
}

//User Food Main Menu Function
int food_menu()
{
    system("CLS");
    int fm;
    printf("1. Breakfast\n2. Lunch\n3. Snacks\n4. Dinner\n5. Food Menu\n6. Main Menu\n");
    printf("Enter Choice: "); scanf("%d", &fm);
    switch (fm)
    {
    case 1:
        breakfast_food_list();
        break;
    case 2:
        lunch_food_list();
        break;
    case 3:
        snacks_food_list();
        break;
    case 4:
        dinner_food_list();
        break;
    case 5:
        food_menu();
        break;
    case 6:
        user_menu();
        break;
    default:
        printf("Invalid Input! [Food Menu]");

    }
}

//User AC Room List Function
int ac_room_list()
{
    system("CLS");
    printf("                       ##       #####      ######    ######    ######   ###     ###  \n");
    printf("                      ####     ##    #     ##    #  ##    ##  ##    ##  ## #   # ##   \n");
    printf("                     ##  ##    ##          ######   ##    ##  ##    ##  ##  # #  ##   \n");
    printf("                    ## ## ##   ##    #     ##   #   ##    ##  ##    ##  ##   #   ##   \n");
    printf("                   ##      ##   #####      ##    #   ######    ######   ##       ##   \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name            ##  Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Berger          --  250 tk      ##\n" );
    printf("\t\t2.      Sandwich        --  180 tk      ##\n" );
    printf("\t\t3.      Beef Stick      --  350 tk      ##\n" );
    printf("\t\t4.      Nachos          --  200 tk      ##\n" );
    printf("\t\t5.      Sicilian Pizza  --  550 tk      ##\n" );
    printf("\t\t6.      Mango Juces     --  80  tk      ##\n" );
    printf("\t\t7.      Chicken Fry     --  450 tk      ##\n" );
    printf("\t\t8.      Water 1 Lt.     --  50  tk      ##\n" );
    printf("\t\t9.      Water 2 Lt.     --  95  tk      ##\n" );

    getch();
    order(1);
    room_menu();
}

//User Non AC Room List Function
int non_ac_room_list()
{
    system("CLS");
    printf("        ###    ##   ######   ###    ##        ##       #####      ######    ######    ######   ###     ###          \n");
    printf("        ## #   ##  ##    ##  ## #   ##       ####     ##    #     ##    #  ##    ##  ##    ##  ## #   # ##          \n");
    printf("        ##  #  ##  ##    ##  ##  #  ##      ##  ##    ##          ######   ##    ##  ##    ##  ##  # #  ##          \n");
    printf("        ##   # ##  ##    ##  ##   # ##     ## ## ##   ##    #     ##   #   ##    ##  ##    ##  ##   #   ##          \n");
    printf("        ##    ###   ######   ##    ###    ##      ##   #####      ##    #   ######    ######   ##       ##          \n\n");
    printf("##################################################################################################################  \n\n");
    printf("\t\t##      Name            ##  Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Berger          --  250 tk      ##\n" );
    printf("\t\t2.      Sandwich        --  180 tk      ##\n" );
    printf("\t\t3.      Beef Stick      --  350 tk      ##\n" );
    printf("\t\t4.      Nachos          --  200 tk      ##\n" );
    printf("\t\t5.      Sicilian Pizza  --  550 tk      ##\n" );
    printf("\t\t6.      Mango Juces     --  80  tk      ##\n" );
    printf("\t\t7.      Chicken Fry     --  450 tk      ##\n" );
    printf("\t\t8.      Water 1 Lt.     --  50  tk      ##\n" );
    printf("\t\t9.      Water 2 Lt.     --  95  tk      ##\n" );

    getch();
    room_menu();
}

//User Room Main Menu Function
int room_menu()
{
    system("CLS");
    int rm;
    printf("1. AC Room\n2. Non AC Room\n3. Main Menu\n\n");
    printf("Enter choice: "); scanf("%d", &rm);
    switch(rm)
    {
    case 1:
        ac_room_list();
        break;
    case 2:
        non_ac_room_list();
        break;
    case 3:
        user_menu();
        break;
    default:
        printf("Error: Invalid Input");
    }
}

//User Main Menu Function
int user_menu()
{
    system("CLS");
    int a;
    printf("\t\t### User Menu ###\n");
    printf("1. Book Room\n2. Order Food\n3. Order History\n4. User Profile\n5. Logout\n");
    printf("Enter choice: ");
    scanf("%d", &a);

    switch(a)
    {
        case 1:
            room_menu();
            break;
        case 2:
            food_menu();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            user_login();
            break;
        default:
            printf("Error! Invalid input.");
    }

}

//Admin Login Function
int admin_login()
{
    printf("Enter your username: ");
    printf("Enter your password: ");
}

//User Login Function
int user_login()
{
    system("CLS");
    char username[50], password[100];


    FILE *log;
    log = fopen("user_info.txt", "r");
    struct user login;
    printf("Username: ");scanf("%s", &username);
    printf("Password: ");scanf("%s", &password);

    /*
    while(fread(&login, sizeof(login), 1, log))
    {
        if(strcmp(username,login.username)==0 && strcmp(password,login.password)==0)
            printf("User Login Succesful\n");
        else
        {
            printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("CLS");
            user_login();
        }
    }
    */
    fclose(log);

    user_menu();
}

//User Registetion function
int registation()
{
    FILE *reg;
    reg = fopen("user_info.txt", "w");
    struct user add;

    printf("Enter username: ");scanf("%s", add.username);
    printf("Enter your name: ");scanf("%s", add.name);
    printf("Enter your email: ");scanf("%s", add.email);
    printf("Enter a password: ");scanf("%s", add.password);
    printf("Enter your NID/Passport no: ");scanf("%s", add.nid);
    printf("Enter your address: ");scanf("%s", add.address);
    printf("Enter your nationality: ");scanf("%s", add.nationality);

    fwrite(&add, sizeof(add), 1, reg);
    fclose(reg);

    printf("\tRegistation Sussefull\nPress any key to Login...");
    getch();
    system("CLS");
    user_login();
}

//Main Function
int main()
{
    int n;
    printf("1. User System\n2. Admin System\n\n");
    printf("Enter your choice: "); scanf("%d", &n);
    system("CLS");
    if(n==1)
    {
        printf("1. Login\n2. Registation\n");
        printf("Enter choice: "); scanf("%d", &n);
        system("CLS");
        if(n==1)
            user_login();
        if(n==2)
            registation();
    }
    else if(n==2)
        admin_login();
    else
        printf("Invalid Input!\n");

    return 0;
}
