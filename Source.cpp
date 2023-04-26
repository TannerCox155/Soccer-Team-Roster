// P08 -- Soccer Team Starter
// Tanner Cox
#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> jerseyNums;
	vector<int> ratingNums;

	int i;
	int playerJersey;
	int playerRating;
	char menuOp;
	bool update = false;
	bool delNum = false;

	cout << "*** Soccer Team Roster ***" << endl;

	do {
		cout << "\n--Menu--" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;

		cout << "Choose an option: ";
		cin >> menuOp;
		cout << endl;

		switch (menuOp) {
		case 'a': //Add 
			cout << "Enter a new player's jersey number: ";
			cin >> playerJersey;
			for (i = 0; i < jerseyNums.size(); i++) {
				if (jerseyNums.at(i) == playerJersey) {
					break;
				}
			}
			if (i < jerseyNums.size()) {
				cout << "   >>> Jersey number " << jerseyNums.at(i) << " already in use! <<<" << endl;
			}
			else {
				jerseyNums.push_back(playerJersey);
				cout << "Enter the player's rating: ";
				cin >> playerRating;
				ratingNums.push_back(playerRating);
				cout << "   >>> Jersey number " << jerseyNums.at(i) << " added! <<<" << endl;
			}
			break;
		case 'd': //Delete jersey number
			cout << "Enter jersey number: ";
			cin >> playerJersey;
			for (i = 0; i < jerseyNums.size(); i++) {
				if (jerseyNums.at(i) == playerJersey) {
					cout << "   >>> Jersey number " << jerseyNums.at(i) << " deleted! <<<" << endl;
					jerseyNums.erase(jerseyNums.begin() + i);
					delNum = true;
					break;
				}
			}
			if (delNum == false) {
			cout << "Jersey number " << playerJersey << " not found!" << endl;
			}
			break;
		case 'u': //Update rating
			cout << "Enter a jersey number: ";
			cin >> playerJersey;
			for (i = 0; i < jerseyNums.size(); i++) {
				if (jerseyNums.at(i) == playerJersey) {
					cout << "Enter a new rating for player: ";
					cin >> playerRating;
					ratingNums.at(i) = playerRating;
					cout << "   >>> Jersey number " << playerJersey << " rating updated! <<<" << endl;
					update = true;
					break;
				}
			}
			if (update == false) {
				cout << "   >>> Jersey number " << playerJersey << " not found! <<<" << endl;
			}
			break;
		case 'r': //Output players above a rating
			cout << "Enter a rating: ";
			cin >> playerRating;
			cout << endl;
			cout << "<<< Ranking Above " << playerRating << " >>>" << endl;
			for (i = 0; i < ratingNums.size(); i++) {
				if (ratingNums.at(i) > playerRating) {
					cout << "Player " << i + 1 << " -- ";
					cout << "Jersey number: " << jerseyNums.at(i) << ", " << "Rating: " << ratingNums.at(i) << endl;
				}
			}
			break;
		case 'o': //Output roster
			cout << "<<< Full Roster >>>" << endl;
			for (i = 0; i < jerseyNums.size(); i++) {
				cout << "Player: " << i + 1 << " -- ";
				cout << "Jersey number: " << jerseyNums.at(i) << ", " << "Rating: " << ratingNums.at(i) << endl;
			}
			break;
		} //end switch

	} while (menuOp != 'q');

	return 0;
}