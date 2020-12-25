**In development!**  

Load or save your data in the JSON format.

## Quick examples

These examples use `std` and `JSON` namespaces.  
  
Create a JSON Object, set a value then print the value
```cpp
Object json;

json["number"] = 42;
    
cout << json["number"].AsNumber() << endl;
```

Load an existing JSON Object, modify a value, then re-save it
```cpp
Object json("examples/basics_object.json");

if (!json.IsValid()) {
    // Handle error
}

json["number"] = json["number"].AsNumber() + 1;
    
json.Save("examples/basics_object_modified.json");
```

Alternatively, you can load an Array instead of an Object
```cpp
Array json("examples/basics_array.json");

if (!json.IsValid()) {
    // Handle error
}

json[0] = json[0].AsNumber() + 1;
    
json.Save("examples/basics_array_modified.json");
```

Create a complete json, using all usable types.
```cpp
Object json;

/* Add basic variables */
json["number"] = 42;
json["string"] = "hello world!";
json["boolean"] = true;

/* Add an Object and an Array */
json.AddObject("object");
json.AddArray("array");

/* Add variables inside the Object */
json["object"].AsObject()["number"] = -42;
json["object"].AsObject()["string"] = "!dlrow olleh";
json["object"].AsObject()["boolean"] = false;
json["object"].AsObject().AddObject("object");
json["object"].AsObject().AddArray("array");

/* Add variables inside the Array */
json["array"].AsArray().AddElement(-42);
json["array"].AsArray().AddElement("!dlrow olleh");
json["array"].AsArray().AddElement(false);
json["array"].AsArray().AddObject();
json["array"].AsArray().AddArray();

/* Print each basic variables */
cout << json["number"].AsNumber() << endl;
cout << json["string"].AsString() << endl;
cout << json["boolean"].AsBool() << endl;

// OR

/* Print the whole JSON */
cout << json.ToString() << endl;
```

## Installation

### Requirements

- g++ (developed with g++ (GCC) 10.2.0 on Arch Linux)
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

## License

LGPLv3 (see the file "LICENSE" at the root)