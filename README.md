**In development!**  
Load or save your data in the JSON format.

## Quick example

```cpp
/* Load a json object from a file */
Object json("examples/basics.json");

/* Check if there is any error */
if (!json.IsValid()) {
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
The lib is located at bin/libjson-parser.a.  
You can run the tests:
```
premake5 tests
```

## Documentation

You have the documentation as comments into the headers.  
It's a very simple json library so the examples cover almost everything you can do with it.