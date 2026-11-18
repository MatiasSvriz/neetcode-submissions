class Twitter {

private:

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int, int>>> tweets;

    int timestamp = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp ++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> output;

        priority_queue<pair<int, int>> heap;

        for(auto tweet : tweets[userId]){

            heap.push(tweet);

        }

        for(int followedId : following[userId]){

            for(auto tweet : tweets[followedId]){

                heap.push(tweet);

            }

        }

        while(!heap.empty() && output.size() < 10){

            output.push_back(heap.top().second);
            heap.pop();

        }

        return output;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
