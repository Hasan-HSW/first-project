#include <iostream>
#include <cmath>
using namespace std;
//x
// Define the structure for a Country
struct Country {
    string name;       // Name of the country
    int x, y;          // Coordinates of the country
    int population;    // Population of the country
    double temperature;// Temperature of the country
    Country* next;     // Pointer to the next country in the list
};

// Initialize pointers for the linked list
Country *head = NULL, *tail = NULL, *temp = NULL, *curr = NULL;

// Function to insert a new country into the list
void InsertCountry() {
	Country* newCountry = new Country();

    // Insert country information
    cout << "Enter a country‘s name: ";
    cin >> newCountry->name;
    cout << "Enter coordinates of the country (x and y): ";
    cin >> newCountry->x >> newCountry->y;
    cout << "Enter population: ";
    cin >> newCountry->population;
    cout << "Enter yearly average temperature: ";
    cin >> newCountry->temperature;

    newCountry->next = NULL;

    // Chek if Country exist
    Country* curr = head;
    while (curr != NULL) {
        if (curr->name == newCountry->name) {
            cout << newCountry->name << " already exists." << endl;
            delete newCountry;
            return;
        }
        curr = curr->next;
    }

    // Orgnaized the Country list
    if (head == NULL || head->name > newCountry->name) {
        newCountry->next = head;
        head = newCountry;
        if (tail == NULL) {
            tail = newCountry;
        }
    } else {
        curr = head;
        while (curr->next != NULL && curr->next->name < newCountry->name) {
            curr = curr->next;
        }
        newCountry->next = curr->next;
        curr->next = newCountry;
        if (newCountry->next == NULL) {
            tail = newCountry;
        }
    }
    cout << "Country added successfully" << endl;
	
}

// Function to delete a country by its name
void DeletionCountryByName() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    if (head == NULL) {
        cout << "Empty List! , we can not delete!" << endl;
    } else {
        Country* prev = NULL;
        Country* curr = head;

        while (curr != NULL) {
            if (curr->name == name) {
                if (prev == NULL) { // Deleting the head node
                    head = curr->next;
                    delete curr;
                    curr = head;
                } else { // Deleting a node in the middle or at the end
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                cout << "Delete Successful!" << endl;
                return; // Exit the function after successful deletion
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        cout << "Country not found." << endl;
    }
}

// Function to delete a country by its coordinates
void DeletionCountryByCoordinate() {
    int x, y;
    cout << "Enter x coordinate to delete: ";
    cin >> x;
    cout << "Enter y coordinate to delete: ";
    cin >> y;

    if (head == NULL) {
        cout << "Empty List! , we can not delete!" << endl;
    } else {
        Country* prev = NULL;
        Country* curr = head;

        while (curr != NULL) {
            if (curr->x == x && curr->y == y) {
                if (prev == NULL) { // Deleting the head node
                    head = curr->next;
                    delete curr;
                    curr = head;
                } else { // Deleting a node in the middle or at the end
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                cout << "Delete Successful!" << endl;
				return ;                
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        cout << "Country not found." << endl;
    }
}

// Function to search and display a country by its name
void SearchAndDisplayCountryByName(string name) {
    Country* temp = head; // Start from the head of the list

    // Traverse the list to find the country
    while (temp != NULL) {
        if (temp->name == name) {
            // If the country is found, display its details
            cout << "Country: " << temp->name << ", Coordinates: (" << temp->x << ", " << temp->y << "), Population: " << temp->population << ", Temperature: " << temp->temperature << endl;
            return;
        }
        temp = temp->next; // Move to the next country
    }

    // If the country is not found, display a message
    cout << "Country not found." << endl;
}

// Function to search and display a country by its coordinates
void SearchAndDisplayCountryByCoordinate(int x, int y) {
    Country* temp = head; // Start from the head of the list

    // Traverse the list to find the country
    while (temp != NULL) {
        if (temp->x == x && temp->y == y) {
            // If the country is found, display its details
            cout << "Country: " << temp->name << ", Coordinates: (" << temp->x << ", " << temp->y << "), Population: " << temp->population << ", Temperature: " << temp->temperature << endl;
            return;
        }
        temp = temp->next; // Move to the next country
    }

    // If the country is not found, display a message
    cout << "Country not found." << endl;
}

// Function to find and display all countries within a specific distance from a given point
void FindCountriesAtSpecificDistance(int x, int y, double distance) {
    Country* temp = head; // Start from the head of the list

    // Traverse the list to find countries within the specified distance
    while (temp != NULL) {
        double dist = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2)); // Calculate the distance
        if (dist <= distance) {
            // If the country is within the distance, display its details
            cout << "Country: " << temp->name << ", Coordinates: (" << temp->x << ", " << temp->y << "), Population: " << temp->population << ", Temperature: " << temp->temperature << endl;
        }
        temp = temp->next; // Move to the next country
    }
}

// Function to print all countries in alphabetical order
void PrintCountriesInAlphabeticalOrder() {
	Country* curr = head;
	
	if(head == NULL){
		cout << "Empty Country!"<<endl;
		cout << "Please Insert Country."<<endl ;		
	}
	
    while (curr != NULL) {
        cout << "Country: " << curr->name << endl;
		cout<<"Coordinates: (" << curr->x << ", " << curr->y << ")"<<endl;
		cout<<"Population: " << curr->population << endl;
		cout<<" Avg Temp: " << curr->temperature << endl;
        curr = curr->next;
        cout << "---------------"<<endl;
        
    }
	
}

int main() {
    int choose;
    string name;
    int x, y;
    double distance;

    do {
        // Display the menu
        cout << "The Menu: \n";
        cout << "******************************\n";
        cout << "1. Insert Country: \n";
        cout << "2. Deletion of the country by name: \n";
        cout << "3. Deletion of the country by coordinate: \n";
        cout << "4. Search and display all information for a country by its name:  \n";
        cout << "5. Search and display all information for a country by its coordinates: \n";
        cout << "6. Print all countries in alphabetical order: \n";
        cout << "7. Find all countries at a specific distance from a specified country: \n";
        cout << "8. Exit program.\n";
        cout << "******************************\n";
        cout << "Enter your choice: ";
        cin >> choose;

        // Execute the corresponding function based on the user's choice
        switch (choose) {
        case 1:
            InsertCountry();
            break;
        case 2:
            DeletionCountryByName();
            break;
        case 3:
            DeletionCountryByCoordinate();
            break;
        case 4:
            cout << "Enter country name to search: ";
            cin >> name;
            SearchAndDisplayCountryByName(name);
            break;
        case 5:
            cout << "Enter x coordinate to search: ";
            cin >> x;
            cout << "Enter y coordinate to search: ";
            cin >> y;
            SearchAndDisplayCountryByCoordinate(x, y);
            break;
        case 6:
            PrintCountriesInAlphabeticalOrder();
            break;
        case 7:
            cout << "Enter x coordinate: ";
            cin >> x;
            cout << "Enter y coordinate: ";
            cin >> y;
            cout << "Enter distance: ";
            cin >> distance;
            FindCountriesAtSpecificDistance(x, y, distance);
            break;
        case 8:
            cout << "Exit Successful!\n";
            cout << "Good Bye.\n";
            break;
        default:
            cout << "Wrong Enter, Try again: \n";
        }
    } while (choose != 8);

    return 0;
}
