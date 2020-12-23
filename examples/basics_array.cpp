#include <iostream>
#include "json-parser/JSON.h"

using namespace std;

int main()
{
	/* Load a json object */
	JSON::Array json("examples/basics_array.json");
	if (json.IsValid()) {
		cout << json.ToString() << endl;
	}
	else {
		cout << "json is not valid: " << json.GetError() << endl;
		return 1;
	}

	/* Modify a json object */
	json[1] = json[1].AsNumber() + 1;
		
	/* Save a json object */
	json.Save("examples/basics_modified.json");

	return 0;
}