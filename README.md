Load or save your data in the JSON format.

## Quick example

```cpp
/* Load a json object from a file */
JSON::Object json("examples/basics.json");

/* Check if there is any error */
if (json.IsValid())
    cout << json.ToString() << endl;
else {
    cout << "json is not valid: " << json.GetError() << endl;
    return 1;
}

/* Modify a variable */
json["number"].AsNumber() = json["number"].AsNumber() + 1;
    
/* Save a json object */
json.Save("examples/basics_modified.json");
```

## Intallation

### Requirements

- g++
- premake5
- make

### Steps (Linux)

```
premake5 gmake
make
```
You now have the lib at bin/libjson-parser.a.  
You can also run the tests:
```
bin/tests
```

## Documentation

You have the documentation as comments into the headers, and the usage from the examples. It's a very simple json
library so there is a quick but almost complete overview of the function:
```cpp
[TODO]
```