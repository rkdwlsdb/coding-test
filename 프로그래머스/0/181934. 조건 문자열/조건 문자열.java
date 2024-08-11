class Solution {
    public int solution(String ineq, String eq, int n, int m) {
        if(eq.equals("=") && n == m) return 1;
        else if(ineq.equals(">") && n > m) return 1;
        else if(ineq.equals("<") && n < m) return 1;
        else return 0;
        
    }
}