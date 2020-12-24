**In development!**  
Load or save your data in the JSON format.

## Quick examples

Create a JSON Object, set a value then print the value
```cpp
JSON::Object json;

json["number"] = 42;
    
std::cout << json["number"].AsNumber() << std::endl;
```

Load an existing JSON Object, modify a value, then re-save it
```cpp
Object json("examples/basics_object.json");

if (!json.IsValid()) {
    cout << "json is not valid: " << json.GetError() << endl;
    return 1;
}

json["number"] = json["number"].AsNumber() + 1;
    
json.Save("examples/basics_object_modified.json");
```

Alternatively, you can load an Array instead of an Object
```cpp
Array json("examples/basics_array.json");

if (!json.IsValid()) {
    cout << "json is not valid: " << json.GetError() << endl;
    return 1;
}

json[0] = json[0].AsNumber() + 1;
    
json.Save("examples/basics_array_modified.json");
```

## Installation

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