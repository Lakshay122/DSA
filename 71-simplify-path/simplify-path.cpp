class Solution {
public:
    string simplifyPath(string path) {
        // go through from the

        vector<string> vec;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".")
                continue;
            else if (part == "..") {

                if (vec.size() > 0)
                    vec.pop_back();
            } else
                vec.push_back(part);
        }

        string ans;

        for (int i = 0; i < vec.size(); i++) {
            ans = ans + "/" + vec[i];
        }
        if (ans == "")
            return "/";
        return ans;
    }
};