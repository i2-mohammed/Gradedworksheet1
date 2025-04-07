# Gradedworksheet1
# Worksheet 1 Development Process

## Implementation Steps
1. **GPS Simulation**:
   - Developed `GPSSensor.h` implementing `ISensor` interface
   - Created data formatting with exact "GPS: lat; lon" output
   - Integrated with CSVHALManager for hardware abstraction

2. **Unit Testing**:
   - Used Catch2 framework as specified
   - Verified sensor properties (ID/dimension)
   - Tested HAL integration (attach/read/release cycles)
   - Ensured output matches worksheet examples exactly

3. **Build System**:
   - Configured Makefile to compile tests with correct naming
   - Preserved directory structure while allowing clean operations

## Key Challenges
1. **HAL Integration**:
   - Initial port number conflicts (fixed by initializing with 2 ports)
   - CSV parsing edge cases (added bounds checking)

2. **Testing**:
   - Achieving exact assertion counts required careful test organization
   - Mock data generation needed precise formatting

## Learnings
1. **IoT System Design**:
   - Importance of hardware abstraction layers
   - Sensor data standardization

2. **Testing**:
   - Catch2 framework best practices
   - Importance of assertion counting for grading

3. **Build Systems**:
   - Makefile configuration for complex projects
   - Directory structure management
   