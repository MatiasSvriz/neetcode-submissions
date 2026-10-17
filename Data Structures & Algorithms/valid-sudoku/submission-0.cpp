class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int size = 9;

        for(int i = 0; i < size; i ++){

            unordered_set<char> seenRows;
            unordered_set<char> seenCols;

            for(int j = 0; j < size; j ++){

                char numRow = board[i][j];
                char numCol = board[j][i];

                if(numRow != '.'){

                    if(seenRows.count(numRow) > 0){
                        return false;
                    }

                    seenRows.insert(numRow);

                }

                if(numCol != '.'){

                    if(seenCols.count(numCol) > 0){
                        return false;
                    }

                    seenCols.insert(numCol);

                }

            }

        }

        for(int startRow = 0; startRow < size; startRow += 3){

            for(int startCol = 0; startCol < size; startCol += 3){

                unordered_set<char> seen;

                for(int row = startRow; row < startRow + 3; row ++){

                    for(int col = startCol; col < startCol + 3; col ++){

                        char num = board[row][col];

                        if(num != '.'){

                            if(seen.count(num) > 0){
                                return false;
                            }

                            seen.insert(num);

                        }

                    }

                }

            }

        }

        return true;

    }
};
