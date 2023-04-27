#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> symmetric_difference(vector<int> set1, vector<int> set2) {
    vector<int> result;
    
    // Сортуємо масиви, щоб можна було швидше знаходити елементи
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    
    // Знаходимо елементи, які є тільки в одній з множин
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(result));
    
    return result;
}

vector<pair<int, int>> cartesian_product(vector<int> set1, vector<int> set2) {
    vector<pair<int, int>> result;
    
    // Знаходимо декартовий добуток множин
    for (int i = 0; i < set1.size(); i++) {
        for (int j = 0; j < set2.size(); j++) {
            result.push_back(make_pair(set1[i], set2[j]));
        }
    }
    
    return result;
}

int main() {
    // Приклад використання обох функцій
    vector<int> set1 = {1, 2, 3, 4};
    vector<int> set2 = {3, 4, 5, 6};
    
    vector<int> sym_diff = symmetric_difference(set1, set2);
    vector<pair<int, int>> cart_prod = cartesian_product(set1, set2);
    
    cout << "Symmetric Difference: ";
    for (int i = 0; i < sym_diff.size(); i++) {
        cout << sym_diff[i] << " ";
    }
    
    cout << "\nCartesian Product: ";
    for (int i = 0; i < cart_prod.size(); i++) {
        cout << "(" << cart_prod[i].first << ", " << cart_prod[i].second << ") ";
    }
    
    return 0;
}
