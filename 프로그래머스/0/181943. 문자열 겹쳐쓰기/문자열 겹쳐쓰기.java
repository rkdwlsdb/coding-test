class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer = "";
        String prefix = my_string.substring(0, s);
        String surfix = "";
        
        if(my_string.substring(s, my_string.length()).length() > overwrite_string.length()){
            surfix = overwrite_string + my_string.substring(s+overwrite_string.length());
        }
        else {
            surfix = overwrite_string;
        }
        
        answer = prefix + surfix;
        return answer;
    }
}