#include <iostream>
#include <string>
#include <mysql++.h>
#include <mysql.h>

#define dbname "dbname"
#define server "localhost"
#define user "root"
#define pass "davoudhamed"

using namespace std;
using namespace mysqlpp;

int main() {
    Connection con(true);
    try {
        con.connect(dbname, server, user, pass);
        cout << "Connected to database\n";
        string s = "SELECT * FROM mirrors_mee WHERE id=1";
        Query q = con.query(s);
        StoreQueryResult sq = q.store();
        StoreQueryResult::iterator it;
        it = sq.begin();
        while (it != sq.end()) {
            Row row = *it;
            cout << row[5] << " " << row[6] << " " << row[7] << endl;
            it++;
        }
    } catch (Exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
