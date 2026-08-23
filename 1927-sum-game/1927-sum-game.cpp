class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int Left_question_marks =0, right_question_marks=0, leftsum=0, rightsum=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?')Left_question_marks++;
            else leftsum+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')right_question_marks++;
            else rightsum+=num[i]-'0';
        }
        return (Left_question_marks+right_question_marks)%2==1 || leftsum - rightsum != (right_question_marks-Left_question_marks)*9/2;
    }
};