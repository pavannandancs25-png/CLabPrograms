int scoreOfParentheses(char* s) {
    int score = 0, depth = 0, i =0;

    while(s[i] != '\0') {
        if(s[i] == '(') {
            depth++;
        } else {
            depth--;
            if(s[i-1] == '(') {
                score += (1 << depth);
            }
        }
        i++;
    }

    return score;
}