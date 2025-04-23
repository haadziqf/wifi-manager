# Contributing to AccessPointWiFi Manager

Thank you for your interest in contributing to the AccessPointWiFi Manager project! This document provides guidelines and instructions for contributing.

## Code of Conduct

By participating in this project, you agree to maintain a respectful and inclusive environment for everyone.

## How to Contribute

There are many ways to contribute to this project:

1. **Reporting Bugs**: Create a detailed issue with steps to reproduce
2. **Suggesting Enhancements**: Open an issue with feature requests or improvements
3. **Code Contributions**: Submit pull requests with bug fixes or new features
4. **Documentation**: Help improve or translate documentation
5. **Testing**: Test the software on different devices and configurations

## Development Workflow

1. **Fork the Repository**: Create your own fork of the project
2. **Create a Branch**: Make a branch for your changes
   ```
   git checkout -b feature/your-feature-name
   ```
3. **Make Changes**: Implement your changes following the coding standards
4. **Test Your Changes**: Ensure your changes work as expected
5. **Commit Your Changes**: Use clear commit messages
   ```
   git commit -m "Add feature: description of your changes"
   ```
6. **Push to Your Fork**: Upload your changes
   ```
   git push origin feature/your-feature-name
   ```
7. **Submit a Pull Request**: Create a PR against the main repository

## Pull Request Process

1. Ensure your code follows the project's coding standards
2. Update documentation if necessary
3. Include tests for new features
4. Ensure all tests pass before submitting
5. Link any relevant issues in your pull request description
6. Wait for review and address any feedback

## Coding Standards

- Follow the existing code style
- Use meaningful variable and function names
- Add comments for complex logic
- Keep functions small and focused
- Use consistent indentation (2 spaces)

### Arduino-Specific Guidelines

- Optimize for memory usage when possible
- Consider power consumption in your implementations
- Follow the [Arduino Style Guide](https://www.arduino.cc/en/Reference/StyleGuide)

## Testing

Before submitting your changes:

1. Test on at least one ESP8266 device
2. Verify all existing functionality still works
3. Test your new feature thoroughly
4. Check memory usage before and after your changes

## Documentation

When adding or changing features, update the relevant documentation:

- Update comments in the code
- Modify the README.md if necessary
- Update DOCUMENTATION.md for technical changes
- Consider adding examples if appropriate

## Commit Message Guidelines

Use clear and descriptive commit messages:

- Start with a verb in imperative form: "Add", "Fix", "Update", "Remove"
- Keep the first line under 50 characters
- Add more detailed description in the body if needed

Example:
```
Add automatic reconnection feature

- Implement reconnection attempts on connection loss
- Add exponential backoff for retry attempts
- Update status indicator during reconnection
```

## License

By contributing to this project, you agree that your contributions will be licensed under the project's MIT License.

## Questions?

If you have any questions about contributing, please open an issue marked as a question, and we'll do our best to help you. 