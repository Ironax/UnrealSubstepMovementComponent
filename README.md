# UnrealSubstepMovementComponent
There is no substeps events in Unreal's Movement Component, 
so I overrided it to provide substeps events accessible in C++ and Blueprints.

You can simply add the code to your project, add it to your actor and subscribe to the OnSubstep Event.
Also, in c++ you can override TickSubstepPhysics(float deltaTime) but dont forget to call the Super

The UpdatedComponent need to be a child of MeshComponent, as substep events need a BodyInstance.
