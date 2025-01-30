class Parent{
    private int type;
    public void getType(){
        System.out.println(type);
    }
};
class Child extends Parent{
    @Override
    public void getType(){
        System.out.println("Inside the child class");
    }
}
class Main{
    public static void main(String args[]){
        
        String ab = "Javacdef";
        unordered_map<char, int> mp;
        for(int i = 0; i < ab.length();i++){
            mp[ab[i]]++;
        }
        for(auto it: mp){
            cout<<(it)<<(*it)<<" ";
        }
    }
}