#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_CHARITIES = 3;

// Function to set up the donation system
void setupDonationSystem(string charities[], double charityTotals[]) {
    cout << "Enter the names of three charities:" << endl;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Charity " << (i + 1) << ": ";
        getline(cin, charities[i]);
        charityTotals[i] = 0.0;
    }
}

// Function to display charity names with corresponding numbers
void displayCharities(string charities[]) {
    cout << "Choose a charity:" << endl;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << (i + 1) << ". " << charities[i] << endl;
    }
}

// Function to record and total each donation
void recordAndTotalDonation(string charities[], double charityTotals[]) {
    int choice;
    double shoppingBill;

    cout << "Enter the charity number (1, 2, or 3), or -1 to show totals: ";
    cin >> choice;

    while (choice != -1) {
        if (choice >= 1 && choice <= NUM_CHARITIES) {
            cout << "Enter the shopping bill amount: $";
            cin >> shoppingBill;

            // Calculate the donation
            double donation = shoppingBill * 0.01;

            // Add the donation to the appropriate total
            charityTotals[choice - 1] += donation;

            // Display the donation details
            cout << "Donation of $" << fixed << setprecision(2) << donation << " to " << charities[choice - 1] << endl;
        } else {
            cout << "Invalid choice. Please enter 1, 2, 3, or -1." << endl;
        }

        cout << "Enter the charity number (1, 2, or 3), or -1 to show totals: ";
        cin >> choice;
    }
}

// Function to show the totals so far
void showTotals(string charities[], double charityTotals[]) {
    cout << "Charity Totals:" << endl;

    // Sort the charities and totals in descending order
    for (int i = 0; i < NUM_CHARITIES - 1; ++i) {
        for (int j = i + 1; j < NUM_CHARITIES; ++j) {
            if (charityTotals[i] < charityTotals[j]) {
                // Swap totals
                double tempTotal = charityTotals[i];
                charityTotals[i] = charityTotals[j];
                charityTotals[j] = tempTotal;

                // Swap charity names
                string tempCharity = charities[i];
                charities[i] = charities[j];
                charities[j] = tempCharity;
            }
        }
    }

    // Display the charities and totals
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << charities[i] << ": $" << fixed << setprecision(2) << charityTotals[i] << endl;
    }

    // Calculate and display the grand total
    double grandTotal = charityTotals[0] + charityTotals[1] + charityTotals[2];
    cout << "GRAND TOTAL DONATED TO CHARITY: $" << fixed << setprecision(2) << grandTotal << endl;
}

int main() {
    string charities[NUM_CHARITIES];
    double charityTotals[NUM_CHARITIES];

    // Task 1 - Set up the donation system
    setupDonationSystem(charities, charityTotals);

    // Task 2 - Record and total each donation
    recordAndTotalDonation(charities, charityTotals);

    // Task 3 - Show the totals so far
    showTotals(charities, charityTotals);

    return 0;
}

