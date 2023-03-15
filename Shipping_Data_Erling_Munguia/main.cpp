#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <iomanip>
#include <vector>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
#include <limits>


using namespace std;

//===========================DEFINE THE SHIPPING DATA TYPE===============================
struct shipping_data {

    int shipment_id;
    char Warehouse_block;
    string Mode_of_Shipment;
    int Customer_care_calls;
    int Customer_rating;
    int Cost_of_the_Product;
    int Prior_purchases;
    string Product_importance;
    char Gender;
    int Discount_offered;
    int Weight_in_gms;
    int Reached_on_Time_YN;
};


//============================FUNCTIONS PROTOTYPES======================================

void display(const shipping_data &shipping);

void parseLine(string line, shipping_data &shipping);

void load(string fname, list<shipping_data> &list);

void displayHeader();

void displayFooter();

int Menu_linked_list_features(list<shipping_data> &list_shipping);

int Menu_vector_features(vector<shipping_data> &v, list<shipping_data> &list_shipping);

//  ================================LINKED LIST========================================
void display_list_elements(list<shipping_data> list);

void display_front_element(list<shipping_data> list);

void Display_Last_Element(list<shipping_data> list);

void Find_The_Element_by_ID(list<shipping_data> list);

void Delete_First_Element(list<shipping_data> &list);

void Delete_Last_Element(list<shipping_data> &list);

void Delete_Nth_Element(list<shipping_data> &list);

bool If_Id_Exists(list<shipping_data> &list, int id);

void Insert_Element_At_Nth_Position(list<shipping_data> &list);

void count_customer_ratings(list<shipping_data> &listCount);

void sort_by_customer_rating(list<shipping_data> &list);

void writeToFile(list<shipping_data> list);

//===================================== VECTOR =========================================
void Populate_Vector_from_the_current_Linked_List(vector<shipping_data> &v, const list<shipping_data> &list_shipping);

void DisplayVector(const vector<shipping_data> &vector);

void display_element_at_index_position(vector<shipping_data> &vector);

bool If_Id_Vector_Exists(vector<shipping_data> &Myvector, int id);

void insert_New_Shipping_Record_at_position_2(vector<shipping_data> &Myvector);

void sort_product_by_price(vector<shipping_data> &vector);

void sort_by_id(vector<shipping_data> &vector);

void display_records_with_customer_rating_less_than_3(vector<shipping_data> &vector2);

void writeToFileVector(vector<shipping_data> &vector);

//====================================== SET ===========================================
void
checkForInvalidProductImportanceValues(const vector<shipping_data> &records, const unordered_set<string> &validValues);

int SetImportanceValues(const vector<shipping_data> &records);

//======================================  MAP ==========================================

int Main_Map_features_Find_and_Display_Given_Id(list<shipping_data> &data);



//================================START MAIN PROGRAM====================================
int main() {

    vector<shipping_data> v;
    list<shipping_data> list_shipping;

    //====LOADING LINKED LIST FROM SMALL SHIPPING FILE====
    load("shipping-data-small.csv", list_shipping);

    //=======LOADING DATA FROM LARGE SHIPPING FILE========
    //load("shipping-data-large.csv", list_shipping); //  To use large shipping data.

    int option;
    while (true) {
        cout << "========================================" << endl;
        cout << "|                Menu                  |" << endl;
        cout << "========================================" << endl;
        cout << "| 1. Menu linked list features         |" << endl;
        cout << "| 2. Menu vector features              |" << endl;
        cout << "| 3. Set features                      |" << endl;
        cout << "| 4. Map features                      |" << endl;
        cout << "| 5. Exit                              |" << endl;
        cout << "========================================" << endl;
        cout << "| Enter option:                        |" << endl;
        cout << "========================================" << endl;


        try {
            if (!(cin >> option)) {
                throw runtime_error("Invalid input. Please enter a numeric value.");
                cout << endl;
            }
        } catch (runtime_error &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (option) {
            case 1:
                cout << endl;
                Menu_linked_list_features(list_shipping);
                cout << endl;
                break;
            case 2:
                cout << endl;
                Menu_vector_features(v, list_shipping);
                cout << endl;
                break;
            case 3:
                cout << endl;
                SetImportanceValues(v);
                cout << endl;
                break;
            case 4:
                cout << endl;
                Main_Map_features_Find_and_Display_Given_Id(list_shipping);
                cout << endl;
                break;
            case 5:
                cout << endl;
                cout << "End of the program." << endl;
                return 0;
            default:
                cout << endl;
                cout << "Invalid option" << endl;
                cout << endl;
        }
    }
    return 0;
}

//=============================SUBMENU LINKED LIST FEATURES===========================
int Menu_linked_list_features(list<shipping_data> &list_shipping) {


    //========================== MENU LIST========================
    int option;
    while (true) {
        cout << "========================================" << endl;
        cout << "|              Menu List               |" << endl;
        cout << "========================================" << endl;
        cout << "| 1. Display all elements              |" << endl;
        cout << "| 2. Display first element             |" << endl;
        cout << "| 3. Display last element              |" << endl;
        cout << "| 4. Find element by ID                |" << endl;
        cout << "| 5. Delete first element              |" << endl;
        cout << "| 6. Delete last element               |" << endl;
        cout << "| 7. Delete nth element                |" << endl;
        cout << "| 8. Insert element at Nth position    |" << endl;
        cout << "| 9. Count customer ratings < 2        |" << endl;
        cout << "| 10. sort by rating                   |" << endl;
        cout << "| 11. Write data to the file           |" << endl;
        cout << "| 12. Exit                             |" << endl;
        cout << "========================================" << endl;
        cout << "| Enter option:                        |" << endl;
        cout << "========================================" << endl;

        try {
            if (!(cin >> option)) {
                throw runtime_error("Invalid input. Please enter a numeric value.");
                cout << endl;
            }
        } catch (runtime_error &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (option) {
            case 1:
                cout << endl;
                display_list_elements(list_shipping);
                cout << endl;
                break;
            case 2:
                cout << endl;
                display_front_element(list_shipping);
                cout << endl;
                break;
            case 3:
                cout << endl;
                Display_Last_Element(list_shipping);
                cout << endl;
                break;
            case 4:
                cout << endl;
                Find_The_Element_by_ID(list_shipping);
                cout << endl;
                break;
            case 5:
                cout << endl;
                Delete_First_Element(list_shipping);
                cout << endl;
                break;
            case 6:
                cout << endl;
                Delete_Last_Element(list_shipping);
                cout << endl;
                break;
            case 7:
                cout << endl;
                Delete_Nth_Element(list_shipping);
                cout << endl;
                break;
            case 8:
                cout << endl;
                Insert_Element_At_Nth_Position(list_shipping);
                cout << endl;
                break;
            case 9:
                cout << endl;
                count_customer_ratings(list_shipping);
                cout << endl;
                break;
            case 10:
                cout << endl;
                sort_by_customer_rating(list_shipping);
                cout << endl;
                break;
            case 11:
                //============ WRITE DATA TO A FILE ====================
                cout << endl;
                writeToFile(list_shipping);
                cout << "The data was saved in the file. " << endl;
                cout << endl;
                break;
            case 12:
                return 0;
            default:
                cout << "Invalid option" << endl;
                cout << endl;
        }
    }

    return 0;
}


//=================SUBMENU FOR VECTOR FEATURES===========================
int Menu_vector_features(vector<shipping_data> &v, list<shipping_data> &list_shipping) {

//    v.clear();     // This for Loop was declared in the populate_vector method.
//    for(shipping_data &d: list_shipping)
//    {
//        v.push_back(d);
//    }

    int option;
    while (true) {
        cout << "================================================" << endl;
        cout << "|                  Menu Vector                 |" << endl;
        cout << "================================================" << endl;
        cout << "| 1. Populate the vector                       |" << endl;
        cout << "| 2. Display all vector elements               |" << endl;
        cout << "| 3. Display element at index position         |" << endl;
        cout << "| 4. Sort products by price                    |" << endl;
        cout << "| 5. Insert New Shipping Record at position 2  |" << endl;
        cout << "| 6. Sort_by_id                                |" << endl;
        cout << "| 7. records_with_customer_rating_less_than_3  |" << endl;
        cout << "| 8. Write data to the file                    |" << endl;
        cout << "| 9. Exit                                      |" << endl;
        cout << "================================================" << endl;
        cout << "| Enter option:                                |" << endl;
        cout << "================================================" << endl;


        try {
            if (!(cin >> option)) {
                throw runtime_error("Invalid input. Please enter a numeric value.");
                cout << endl;
            }
        } catch (runtime_error &e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (option) {


            case 1:
                cout << endl;
                Populate_Vector_from_the_current_Linked_List(v, list_shipping);
                cout << endl;
                break;
            case 2:
                cout << endl;
                DisplayVector(v);
                cout << endl;
                break;
            case 3:
                cout << endl;
                display_element_at_index_position(v);
                cout << endl;
                break;
            case 4:
                cout << endl;
                sort_product_by_price(v);
                cout << endl;
                break;
            case 5:
                cout << endl;
                insert_New_Shipping_Record_at_position_2(v);
                cout << endl;
                break;
            case 6:
                cout << endl;
                sort_by_id(v);
                cout << endl;
                break;
            case 7:
                cout << endl;
                display_records_with_customer_rating_less_than_3(v);
                cout << endl;
                break;
            case 8:
                //============ WRITE DATA TO A FILE ====================
                cout << endl;
                writeToFileVector(v);
                cout << "The data was saved in the file. " << endl;
                cout << endl;
                break;
            case 9:
                return 0;
            default:
                cout << endl;
                cout << "Invalid option" << endl;
                cout << endl;
        }
    }

    return 0;
}


//=================================  DISPLAY DATA  =====================================
void display(const shipping_data &shipping) {

    cout << left << "|"
         << setw(6) << shipping.shipment_id << "| "
         << setw(8) << shipping.Warehouse_block << " |"
         << setw(10) << shipping.Mode_of_Shipment << "|"
         << setw(10) << shipping.Customer_care_calls << "|"
         << setw(13) << shipping.Customer_rating << "|"
         << setw(15) << shipping.Cost_of_the_Product << "|"
         << setw(7) << shipping.Prior_purchases << "|"
         << setw(18) << shipping.Product_importance << "|"
         << setw(7) << shipping.Gender << "|"
         << setw(10) << shipping.Discount_offered << "|"
         << setw(9) << shipping.Weight_in_gms << "|"
         << setw(7) << shipping.Reached_on_Time_YN << "|"
         << endl;
}

//=============================PARSELINE OF THE DATA==================================
void parseLine(string line, shipping_data &shipping) {

    string temp;
    stringstream sData(line);
    getline(sData, temp, ',');
    shipping.shipment_id = stoi(temp);
    getline(sData, temp, ',');
    shipping.Warehouse_block = temp[0];
    getline(sData, temp, ',');
    shipping.Mode_of_Shipment = temp;
    getline(sData, temp, ',');
    shipping.Customer_care_calls = stoi(temp);
    getline(sData, temp, ',');
    shipping.Customer_rating = stoi(temp);
    getline(sData, temp, ',');
    shipping.Cost_of_the_Product = stoi(temp);
    getline(sData, temp, ',');
    shipping.Prior_purchases = stoi(temp);
    getline(sData, temp, ',');
    shipping.Product_importance = temp;
    getline(sData, temp, ',');
    shipping.Gender = temp[0];
    getline(sData, temp, ',');
    shipping.Discount_offered = stoi(temp);
    getline(sData, temp, ',');
    shipping.Weight_in_gms = stoi(temp);
    getline(sData, temp, ',');
    shipping.Reached_on_Time_YN = stoi(temp);
    getline(sData, temp, ',');

}

//================================LOAD DATA TO A FILE====================================
void load(string fname, list <shipping_data> &list) {
    ifstream fin(fname);

    if (fin) {
        string line;
        getline(fin, line);
        while (getline(fin, line)) {
            shipping_data shipping;
            parseLine(line, shipping);
            list.push_back(shipping);
        }
        fin.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

//=====================WRITE DATA TO A FILE FROM LINKED-LIST===========================
void writeToFile(list<shipping_data> list) {
    ofstream out("Out.txt");
    if (out) {

        for (shipping_data temp: list) {
            out << left
                << setw(8) << temp.shipment_id
                << setw(7) << temp.Warehouse_block
                << setw(8) << temp.Mode_of_Shipment
                << setw(5) << temp.Customer_care_calls
                << setw(10) << temp.Customer_rating
                << setw(5) << temp.Cost_of_the_Product
                << setw(10) << temp.Prior_purchases
                << setw(10) << temp.Product_importance
                << setw(10) << temp.Gender
                << setw(5) << temp.Discount_offered
                << setw(10) << temp.Weight_in_gms
                << setw(5) << temp.Reached_on_Time_YN
                << endl;
        }
    }
}

//=================================FUNCTION DISPLAY HEADER=============================
void displayHeader() {
    cout << left << setfill('-')
         << setw(7) << "+" << setw(11) << "+"
         << setw(11) << "+" << setw(11) << "+"
         << setw(14) << "+" << setw(16) << "+"
         << setw(8) << "+" << setw(19) << "+"
         << setw(8) << "+" << setw(11) << "+"
         << setw(10) << "+"
         << setw(8) << "+" << "+" << endl;

    cout << left << setfill(' ') << "| "
         << setw(5) << "ID" << "|"
         << setw(10) << "Warehouse" << "|"
         << setw(10) << "Shipment" << "|"
         << setw(10) << "C_calls" << "|"
         << setw(13) << "C_rating" << "|"
         << setw(15) << "CostProduct" << "|"
         << setw(7) << "Prior" << "|"
         << setw(18) << "Prod_importance" << "|"
         << setw(7) << "Gender" << "|"
         << setw(10) << "Discount" << "|"
         << setw(9) << "Weight" << "|"
         << setw(6) << "OnTime" << "|"
         << endl;

    cout << left << setfill('-')
         << setw(7) << "+" << setw(11) << "+"
         << setw(11) << "+" << setw(11) << "+"
         << setw(14) << "+" << setw(16) << "+"
         << setw(8) << "+" << setw(19) << "+"
         << setw(8) << "+" << setw(11) << "+"
         << setw(10) << "+"
         << setw(8) << "+" << "+" << endl;

    cout << setfill(' ');
}

//=================================FUNCTION DISPLAY FOOTER================================
void displayFooter() {
    cout << left << setfill('-')
         << setw(7) << "+" << setw(11) << "+"
         << setw(11) << "+" << setw(11) << "+"
         << setw(14) << "+" << setw(16) << "+"
         << setw(8) << "+" << setw(19) << "+"
         << setw(8) << "+" << setw(11) << "+"
         << setw(10) << "+"
         << setw(8) << "+" << "+" << endl;
}

//==================================1.LINKED LIST FEATURES===============================
//====================DISPLAYING LIST OF ELEMENTS FROM THE LINKED-LIST===================
void display_list_elements(list<shipping_data> list) {

    displayHeader();
    int i = 0;
    for (shipping_data temp: list) {

        cout << left << "|"
             << setw(5) << temp.shipment_id << "| "
             << setw(10) << temp.Warehouse_block << "|"
             << setw(10) << temp.Mode_of_Shipment << "|"
             << setw(10) << temp.Customer_care_calls << "|"
             << setw(13) << temp.Customer_rating << "|"
             << setw(15) << temp.Cost_of_the_Product << "|"
             << setw(7) << temp.Prior_purchases << "|"
             << setw(18) << temp.Product_importance << "|"
             << setw(7) << temp.Gender << "|"
             << setw(10) << temp.Discount_offered << "|"
             << setw(9) << temp.Weight_in_gms << "|"
             << setw(7) << temp.Reached_on_Time_YN << "|"
             << endl;
        i++;
        if (i % 1000 == 0) {
            string temp;
            cout << "press any key to continue" << endl;
            cin >> temp;
        }

    }
    displayFooter();
}

//========================DISPLAYING FIRST ELEMENT FROM THE LINKED-LIST=================
void display_front_element(list<shipping_data> list) {

    displayHeader();

    if (list.empty()) {
        cout << "The linked list is empty!" << endl;
        return;
    }

    shipping_data temp = list.front();

    cout << left << "|"
         << setw(5) << temp.shipment_id << "| "
         << setw(10) << temp.Warehouse_block << "|"
         << setw(10) << temp.Mode_of_Shipment << "|"
         << setw(10) << temp.Customer_care_calls << "|"
         << setw(13) << temp.Customer_rating << "|"
         << setw(15) << temp.Cost_of_the_Product << "|"
         << setw(7) << temp.Prior_purchases << "|"
         << setw(18) << temp.Product_importance << "|"
         << setw(7) << temp.Gender << "|"
         << setw(10) << temp.Discount_offered << "|"
         << setw(9) << temp.Weight_in_gms << "|"
         << setw(7) << temp.Reached_on_Time_YN << "|"
         << endl;

    displayFooter();

}

//======================DISPLAYING LAST ELEMENT FROM THE LINKED-LIST===================

void Display_Last_Element(list<shipping_data> list) {

    displayHeader();

    if (list.empty()) {
        cout << "The linked list is empty!" << endl;
        return;
    }
    shipping_data temp = list.back();

    cout << left << "|"
         << setw(5) << temp.shipment_id << "| "
         << setw(10) << temp.Warehouse_block << "|"
         << setw(10) << temp.Mode_of_Shipment << "|"
         << setw(10) << temp.Customer_care_calls << "|"
         << setw(13) << temp.Customer_rating << "|"
         << setw(15) << temp.Cost_of_the_Product << "|"
         << setw(7) << temp.Prior_purchases << "|"
         << setw(18) << temp.Product_importance << "|"
         << setw(7) << temp.Gender << "|"
         << setw(10) << temp.Discount_offered << "|"
         << setw(9) << temp.Weight_in_gms << "|"
         << setw(7) << temp.Reached_on_Time_YN << "|"
         << endl;

    displayFooter();

}

//====================DISPLAYING AN ELEMENT FROM THE LINKED-LIST BY ID=================
void Find_The_Element_by_ID(list<shipping_data> list) {
    int id;
    cout << "Please enter the Id:\n";
    cin >> id;

    displayHeader();

    for (shipping_data temp: list) {
        if (temp.shipment_id == id) {
            cout << left << "|"
                 << setw(5) << temp.shipment_id << "| "
                 << setw(10) << temp.Warehouse_block << "|"
                 << setw(10) << temp.Mode_of_Shipment << "|"
                 << setw(10) << temp.Customer_care_calls << "|"
                 << setw(13) << temp.Customer_rating << "|"
                 << setw(15) << temp.Cost_of_the_Product << "|"
                 << setw(7) << temp.Prior_purchases << "|"
                 << setw(18) << temp.Product_importance << "|"
                 << setw(7) << temp.Gender << "|"
                 << setw(10) << temp.Discount_offered << "|"
                 << setw(9) << temp.Weight_in_gms << "|"
                 << setw(7) << temp.Reached_on_Time_YN << "|"
                 << endl;
            return;
        }
    }
    cout << "Data from this ID is not found" << endl;

}


//====================DELETE FIRST ELEMENT FROM THE LINKED-LIST=================
void Delete_First_Element(list<shipping_data> &list) {

    displayHeader();

    cout << setfill(' ');


    if (list.empty()) {
        cout << "The liked list is empty!" << endl;
        return;
    }

    shipping_data temp = list.front();
    list.pop_front();

    cout << left << "|"
         << setw(5) << temp.shipment_id << "| "
         << setw(10) << temp.Warehouse_block << "|"
         << setw(10) << temp.Mode_of_Shipment << "|"
         << setw(10) << temp.Customer_care_calls << "|"
         << setw(13) << temp.Customer_rating << "|"
         << setw(15) << temp.Cost_of_the_Product << "|"
         << setw(7) << temp.Prior_purchases << "|"
         << setw(18) << temp.Product_importance << "|"
         << setw(7) << temp.Gender << "|"
         << setw(10) << temp.Discount_offered << "|"
         << setw(9) << temp.Weight_in_gms << "|"
         << setw(7) << temp.Reached_on_Time_YN << "|"
         << endl;

    displayFooter();
    cout << " The first element displayed previously, was deleted from the linked list." << endl;
    cout << " " << endl;

}

//====================DELETE FIRST ELEMENT FROM THE LINKED-LIST=================
void Delete_Last_Element(list<shipping_data> &list) {

    displayHeader();

    if (list.empty()) {
        cout << "The liked list is empty!" << endl;
        return;
    }

    shipping_data temp = list.back();
    list.pop_back();

    cout << left << "|"
         << setw(5) << temp.shipment_id << "| "
         << setw(10) << temp.Warehouse_block << "|"
         << setw(10) << temp.Mode_of_Shipment << "|"
         << setw(10) << temp.Customer_care_calls << "|"
         << setw(13) << temp.Customer_rating << "|"
         << setw(15) << temp.Cost_of_the_Product << "|"
         << setw(7) << temp.Prior_purchases << "|"
         << setw(18) << temp.Product_importance << "|"
         << setw(7) << temp.Gender << "|"
         << setw(10) << temp.Discount_offered << "|"
         << setw(9) << temp.Weight_in_gms << "|"
         << setw(7) << temp.Reached_on_Time_YN << "|"
         << endl;

    displayFooter();
    cout << " The last element displayed previously, was deleted from the linked list." << endl;
    cout << " " << endl;

}

//================DELETE Nth ELEMENT FROM THE LINKED-LIST=======================
void Delete_Nth_Element(list<shipping_data> &list) {
    int ShippingPosition;
    cout << "Please enter the position you would like to delete: ";
    cin >> ShippingPosition;
    cout << " " << endl;

    if (ShippingPosition < 1 || ShippingPosition > list.size()) {
        cout << "It is an invalid position" << endl;
        return;
    }
    auto iterator = list.begin();
    advance(iterator, ShippingPosition - 1);
    list.erase(iterator);

//    display_list_elements(list);
    cout << "The data from position :" << ShippingPosition << " Was deleted." << endl;
    cout << " " << endl;

}

//=============CHECKING IF THE ID INSERTED EXITS IN THE LINKED-LIST=============
bool If_Id_Exists(list<shipping_data> &list, int id) {
    for (auto &temp: list) {
        if (temp.shipment_id == id) {
            cout << "Id already exists in the linked list." << endl;
            return true;
        }
    }
    return false;
}

//===========INSERT AN ELEMENT AT Nth POSITION IN THE LINKED-LIST===============
void Insert_Element_At_Nth_Position(list<shipping_data> &list) {
    int ShippingPosition;
    int id;

    shipping_data New_Element;

    cout << "Enter the Shipping position: ";
    cin >> ShippingPosition;
    if (!cin) {
        cout << "Invalid input for shipping position" << endl;
        return;
    }

    cout << "Enter the Shipping ID: ";
    cin >> New_Element.shipment_id;
    id = New_Element.shipment_id;
    if (If_Id_Exists(list, id)) {
        return;
    }

    cout << "Enter the Warehouse House: ";
    cin >> New_Element.Warehouse_block;
    cout << "Enter the mode of Shipment: ";
    cin.ignore(1000, '\n');
    getline(cin, New_Element.Mode_of_Shipment);
    cout << "Enter Customer care calls: ";
    cin >> New_Element.Customer_care_calls;
    cout << "Enter Customer rating: ";
    cin >> New_Element.Customer_rating;
    cout << "Enter Cost of the product: ";
    cin >> New_Element.Cost_of_the_Product;
    cout << "Enter Prior purchases: ";
    cin >> New_Element.Prior_purchases;
    cout << "Enter Product Importance: ";
    cin.ignore(1000, '\n');
    getline(cin, New_Element.Product_importance);
    cout << "Enter the Gender: ";
    cin >> New_Element.Gender;
    cout << "Enter Discount offered: ";
    cin >> New_Element.Discount_offered;
    cout << "Enter weight in gms: ";
    cin >> New_Element.Weight_in_gms;
    cout << "Enter Reached on time YN: ";
    cin >> New_Element.Reached_on_Time_YN;

    if (ShippingPosition < 1 || ShippingPosition > list.size() + 1) {
        cout << "Invalid position" << endl;
        return;
    }

    auto iterator = list.begin();
    advance(iterator, ShippingPosition - 1);
    list.insert(iterator, New_Element);
    display_list_elements(list);
    cout << " " << endl;

}

//=================COUNT CUSTOMER RATING < 2 IN THE LINKED-LIST=================
void count_customer_ratings(list<shipping_data> &listCount) {

    list<shipping_data> copy;
    int count = count_if(listCount.begin(), listCount.end(),
                         [](const shipping_data &element) { return element.Customer_rating < 2; });
    cout << "Number of customers with ratings less than 2 is: " << count << endl;

    cout << endl;
}

//=================SORTING BY CUSTOMER RATING  IN THE LINKED-LIST===============
void sort_by_customer_rating(list<shipping_data> &list) {
    list.sort([](const shipping_data &a, const shipping_data &b) { return a.Customer_rating < b.Customer_rating; });
    display_list_elements(list);
    cout << endl;
}


//============================3.VECTOR FEATURES================================

//================================POPULATE THE VECTOR =========================
void Populate_Vector_from_the_current_Linked_List(vector<shipping_data> &v, const list<shipping_data> &list_shipping) {

    for (const shipping_data &d: list_shipping) {
        v.push_back(d);
    }
    cout << " Data was populated to the vector." << endl;

}

//====================== DISPLAY THE DATA FROM VECTOR ========================
void DisplayVector(const vector <shipping_data> &vector) {

    displayHeader();
    // =============================CHECK FOR VECTOR USER=====================
    for (auto iter = vector.begin(); iter != vector.end(); iter++) {
        display(*iter);  // * = get the element that the iter points to, which is a struct.
    }
    displayFooter();
}


//===========DISPLAY AN ELEMENT AT THE INDEX POSITION FROM USER===============
void display_element_at_index_position(vector<shipping_data> &vector) {
    int index;
    cout << "Please enter index position: ";
    cin >> index;
    if (index < 0 || index > vector.size()) {
        cout << "Invalid index position. The index must be between 0 and " << vector.size() << endl;
        return;
    }
    displayHeader();

    shipping_data temp = vector[index];
    cout << left << "|"
         << setw(5) << temp.shipment_id << "| "
         << setw(10) << temp.Warehouse_block << "|"
         << setw(10) << temp.Mode_of_Shipment << "|"
         << setw(10) << temp.Customer_care_calls << "|"
         << setw(13) << temp.Customer_rating << "|"
         << setw(15) << temp.Cost_of_the_Product << "|"
         << setw(7) << temp.Prior_purchases << "|"
         << setw(18) << temp.Product_importance << "|"
         << setw(7) << temp.Gender << "|"
         << setw(10) << temp.Discount_offered << "|"
         << setw(9) << temp.Weight_in_gms << "|"
         << setw(7) << temp.Reached_on_Time_YN << "|"
         << endl;

    displayFooter();

    cout << " " << endl;
}

//==============CHECKING IF THE ID INSERTED EXITS IN THE VECTOR==============
bool If_Id_Vector_Exists(vector<shipping_data> &Myvector, int id) {
    for (auto &temp: Myvector) {
        if (temp.shipment_id == id) {
            cout << "Id already exists in the vector data." << endl;
            return true;
        }
    }
    return false;
}

//================INSERT A NEW SHIPPING RECORD AT POSITION 2=================
void insert_New_Shipping_Record_at_position_2(vector<shipping_data> &Myvector) {

    shipping_data new_shipping_record;

    int id;
    int index;
    cout << "Please enter index position: ";
    cin >> index;


    if (index < 0 || index > Myvector.size()) {
        cout << "Invalid index position. The index must be between 0 and " << Myvector.size() << endl;
        return;
    }

    cout << "Enter the Shipping ID: ";
    cin >> new_shipping_record.shipment_id;
    id = new_shipping_record.shipment_id;
    if (If_Id_Vector_Exists(Myvector, id)) {
        return;
    }

    cout << "Enter the Warehouse House: ";
    cin >> new_shipping_record.Warehouse_block;
    cout << "Enter the mode of Shipment: ";
    cin.ignore(1000, '\n');
    getline(cin, new_shipping_record.Mode_of_Shipment);
    cout << "Enter Customer care calls: ";
    cin >> new_shipping_record.Customer_care_calls;
    cout << "Enter Customer rating: ";
    cin >> new_shipping_record.Customer_rating;
    cout << "Enter Cost of the product: ";
    cin >> new_shipping_record.Cost_of_the_Product;
    cout << "Enter Prior purchases: ";
    cin >> new_shipping_record.Prior_purchases;
    cout << "Enter Product Importance: ";
    cin.ignore(1000, '\n');
    getline(cin, new_shipping_record.Product_importance);
    cout << "Enter the Gender: ";
    cin >> new_shipping_record.Gender;
    cout << "Enter Discount offered: ";
    cin >> new_shipping_record.Discount_offered;
    cout << "Enter weight in gms: ";
    cin >> new_shipping_record.Weight_in_gms;
    cout << "Enter Reached on time YN: ";
    cin >> new_shipping_record.Reached_on_Time_YN;

    Myvector.insert(Myvector.begin() + index, new_shipping_record);

    DisplayVector(Myvector);

    cout << endl;

}

//============SORTING THE VECTOR IN ORDER OF PRODUCT COST ===================
void sort_product_by_price(vector<shipping_data> &vector) {


    sort(vector.begin(), vector.end(),
         [](const shipping_data &a, const shipping_data &b) { return a.Cost_of_the_Product < b.Cost_of_the_Product; });
    DisplayVector(vector);

    cout << endl;
}

//===============SORTING THE VECTOR IN ORDER OF ID  ========================
void sort_by_id(vector<shipping_data> &vector) {


    sort(vector.begin(), vector.end(),
         [](const shipping_data &a, const shipping_data &b) { return a.shipment_id < b.shipment_id; });
    DisplayVector(vector);
    cout << endl;
}

//=====DISPLAYING SHIPPING RECORDS WHERE CUSTOMER RATING IS LESS THAN 3=====
void display_records_with_customer_rating_less_than_3(vector<shipping_data> &vector2) {

    displayHeader();
    vector<shipping_data> copy;
    copy_if(vector2.begin(), vector2.end(), back_inserter(copy),
            [](const shipping_data &record) { return record.Customer_rating < 3; });

    for (auto record: copy) {
        display(record);
    }
    displayFooter();
    cout << endl;

}

//============================4.SET FEATURES=================================
void
checkForInvalidProductImportanceValues(const vector<shipping_data> &records, const unordered_set<string> &validValues) {

    for (auto &record: records) {
        string ProductImport = record.Product_importance;
        auto iter = validValues.find(ProductImport);// Using iterator as required.
        if (iter == validValues.end()) {
            cout << "The Record with Id: " << record.shipment_id << " has invalid value: "
                 << record.Product_importance << "."<<endl;
        }
    }
}


//====================METHOD SET IMPORTANCE VALUES==========================
int SetImportanceValues(const vector<shipping_data> &records) {

    unordered_set<string> validValues;
    validValues.insert("low");
    validValues.insert("medium");
    validValues.insert("high");

    checkForInvalidProductImportanceValues(records, validValues);
    return 0;

}

//============================5.MAP FEATURES===============================

int Main_Map_features_Find_and_Display_Given_Id(list<shipping_data> &data) {

    //==CREATING A <unordered_map> FROM THE CONTENTS OF THE LINKED-LIST===
    unordered_map<int, shipping_data> map;
    for (shipping_data &d: data) {
        if (map.find(d.shipment_id) == map.end()) {
            map[d.shipment_id] = d;
        }
    }
    //============FIND AND DISPLAY A RECORD GIVEN AN ID===================

    int findId;
    cout << "Please enter an Id: ";
    cin >> findId;

    auto iter = map.find(findId);
    if (iter != map.end()) {
        displayHeader();
        display(iter->second);
        displayFooter();

    } else {
        cout << "Record with ID " << findId << " not found.\n";
    }
    return 0;
}

//=====================WRITE DATA TO A FILE FROM VECTOR==================
void writeToFileVector(vector<shipping_data> &vector) {
    ofstream out1("OutVector.txt");
    if (out1) {

        for (shipping_data fileVector: vector) {
            out1 << left
                 << setw(8) << fileVector.shipment_id
                 << setw(7) << fileVector.Warehouse_block
                 << setw(8) << fileVector.Mode_of_Shipment
                 << setw(5) << fileVector.Customer_care_calls
                 << setw(10) << fileVector.Customer_rating
                 << setw(5) << fileVector.Cost_of_the_Product
                 << setw(10) << fileVector.Prior_purchases
                 << setw(10) << fileVector.Product_importance
                 << setw(10) << fileVector.Gender
                 << setw(5) << fileVector.Discount_offered
                 << setw(10) << fileVector.Weight_in_gms
                 << setw(5) << fileVector.Reached_on_Time_YN
                 << endl;
        }
    }
}







