class OrderedStream {
public:
    vector<string> stream;
    int ptr;

    OrderedStream(int n) {
        stream.resize(n + 1);
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;

        vector<string> ans;

        while (ptr < stream.size() && stream[ptr] != "") {
            ans.push_back(stream[ptr]);
            ptr++;
        }

        return ans;
    }
};