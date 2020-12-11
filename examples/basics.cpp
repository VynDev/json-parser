#include <iostream>
#include "json-parser/JSON.h"

using namespace std;

int main()
{
	/* Load a json object */

	JSON::Object json("examples/basics.json");
	if (json.IsValid())
		cout << json.ToString() << endl;
	else {
		cout << "json is not valid: " << json.GetError() << endl;
		return 1;
	}

	/* Modify a json object */

	// json["number"] = json["number"].HasNumber() + 1; // TODO
		
	/* Save a json object */

	json.Save("examples/basics_saved.json");
	

	return 0;
}