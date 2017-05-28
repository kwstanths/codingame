#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int pop_card(queue<int>& mq){
	if (mq.empty()) return -1;
	int temp = mq.front();
	mq.pop();
	return temp;
}

void m_exit(string text){
	cout << text << endl;
	exit(0);
}

int card_value(string card){
	try {
		return stoi(card);
	}catch (...){
		if (card == "J") return 11;
		if (card == "Q") return 12;
		if (card == "K") return 13;
		if (card == "A") return 14;
	}
}

void append_queue(queue<int>& A, queue<int>& B){
	while(!B.empty()){
		int temp = pop_card(B);
		A.push(temp);
	}
	return;
}

void battle(queue<int>& player_one_queue, queue<int>& player_two_queue, queue<int>& temp_queue_one, queue<int>& temp_queue_two){
	int player_one_card_1 = pop_card(player_one_queue);
	int player_one_card_2 = pop_card(player_one_queue);
	int player_one_card_3 = pop_card(player_one_queue);
	int player_two_card_1 = pop_card(player_two_queue);
	int player_two_card_2 = pop_card(player_two_queue);
	int player_two_card_3 = pop_card(player_two_queue);

	int player_one_battle_card = pop_card(player_one_queue);
	int player_two_battle_card = pop_card(player_two_queue);
	if (player_one_battle_card == -1 || player_two_battle_card == -1) m_exit("PAT");

	temp_queue_one.push(player_one_card_1);
	temp_queue_one.push(player_one_card_2);
	temp_queue_one.push(player_one_card_3);
	temp_queue_one.push(player_one_battle_card);
	temp_queue_two.push(player_two_card_1);
	temp_queue_two.push(player_two_card_2);
	temp_queue_two.push(player_two_card_3);
	temp_queue_two.push(player_two_battle_card);

	if (player_one_battle_card > player_two_battle_card){
		append_queue(player_one_queue, temp_queue_one);
		append_queue(player_one_queue, temp_queue_two);
	}else if (player_one_battle_card < player_two_battle_card){
		append_queue(player_two_queue, temp_queue_one);
		append_queue(player_two_queue, temp_queue_two);
	}else battle(player_one_queue, player_two_queue, temp_queue_one, temp_queue_two);

}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	queue<int> player_one_queue;
	int n; // the number of cards for player 1
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string cardp1; // the n cards of player 1
		cin >> cardp1; cin.ignore();
		player_one_queue.push(card_value(cardp1.substr(0,cardp1.length() -1)));
	}

	queue<int> player_two_queue;
	int m; // the number of cards for player 2
	cin >> m; cin.ignore();
	for (int i = 0; i < m; i++) {
		string cardp2; // the m cards of player 2
		cin >> cardp2; cin.ignore();
		player_two_queue.push(card_value(cardp2.substr(0,cardp2.length()-1)));
	}

	int game_steps = -1;
	for(;;){
		game_steps ++;
		int player_one_card = pop_card(player_one_queue);
		int player_two_card = pop_card(player_two_queue);
		if (player_one_card == player_two_card && player_two_card == -1) m_exit("PAT");
		else if (player_two_card == -1) m_exit("1 " + to_string(game_steps));
		else if (player_one_card == -1) m_exit("2 " + to_string(game_steps));
		else if (player_one_card > player_two_card) {
			player_one_queue.push(player_one_card);
			player_one_queue.push(player_two_card);
		}
		else if (player_two_card > player_one_card) {
			player_two_queue.push(player_one_card);
			player_two_queue.push(player_two_card);
		}
		else {
			queue<int> temp_queue_one;
			queue<int> temp_queue_two;
			temp_queue_one.push(player_one_card);
			temp_queue_two.push(player_two_card);
			battle(player_one_queue, player_two_queue, temp_queue_one, temp_queue_two);
		}


	}


}
