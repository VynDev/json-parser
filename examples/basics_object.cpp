#include <iostream>
#include "json-parser/JSON.h"

using namespace std;

int main()
{
	/* Load a json object */
	JSON::Object json("examples/basics_object.json");
	if (json.IsValid()) {
		cout << json.ToString() << endl;
	}
	else {
		cout << "json is not valid: " << json.GetError() << endl;
		return 1;
	}

	/* Modify a json object */
	json["number"] = json["number"].AsNumber() + 1;

	/* Save a json object */
	json.Save("examples/basics_object_modified.json");

	return 0;
}