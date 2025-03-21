#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end()); // Store available ingredients
        unordered_map<string, vector<string>> recipeMap; // Map a recipe to its ingredients
        unordered_set<string> resultSet; // To store final recipes

        for (int i = 0; i < recipes.size(); ++i) {
            recipeMap[recipes[i]] = ingredients[i];
        }

        bool progress = true; // Keep track if we make progress in an iteration

        while (progress) {
            progress = false;
            for (const auto& [recipe, requiredIngredients] : recipeMap) {
                if (resultSet.count(recipe)) continue; // Already added

                bool canMake = true;
                for (const string& ing : requiredIngredients) {
                    if (!available.count(ing)) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    available.insert(recipe); // Mark recipe as available ingredient
                    resultSet.insert(recipe); // Add to final result
                    progress = true;
                }
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
