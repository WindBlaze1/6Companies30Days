class Trie{
    public:
    int cnt;
    bool end;
    Trie* child[26];
    Trie(){
        cnt=0;
        end=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class Solution{
public:
    void insert(string& word, Trie* curr,int pos){
        if(pos==word.size()){
            curr->cnt++;
            curr->end=true;
            return;
        }
        curr->cnt++;
        if(!curr->child[word[pos]-'a']){
            curr->child[word[pos]-'a']=new Trie();
        }
        insert(word,curr->child[word[pos]-'a'],pos+1);
    }
    
    pair<bool,Trie*> search(string& pre,Trie* curr,int pos,string& temp){
        if(!curr)return {false,NULL};
        if(pre.size()==pos)return {true,curr};
        temp+=pre[pos];
        return search(pre,curr->child[pre[pos]-'a'],pos+1,temp);
    }
    
    void insertAll(Trie* curr,string& temp,vector<string>& t){
        if(curr->end){
            t.push_back(temp);
            for(int i=0;i<26;i++){
                if(curr->child[i]){
                    temp+=char(i+97);
                    insertAll(curr->child[i],temp,t);
                    temp.pop_back();
                }
            }
            return;
        }
        for(int i=0;i<26;i++){
            if(curr->child[i]){
                temp+=char(i+97);
                insertAll(curr->child[i],temp,t);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        Trie * root=new Trie();
        for(int i=0;i<n;i++){
            insert(contact[i],root,0);
        }
        string pre="";
        for(int i=0;i<s.length();i++){
            pre+=s[i];
            string temp="";
            auto p=search(pre,root,0,temp);
            if(p.first){
                vector<string> t;
                insertAll(p.second,temp,t);
                ans.push_back(t);
            }else{
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};
