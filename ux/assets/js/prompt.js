const userInput = document.getElementById('userInput');

userInput.addEventListener('click', () => {
    if (inputField.value === '1857e2cb374e86db84f27a8550dc6e24') {
        inputField.value = '';
    }
});

const handleInputSubmit = (event) => {
    event.preventDefault();
    const inputValue = userInput.value;
    alert(`You entered: ${inputValue}`);
};

const formElement = document.querySelector('form');
formElement.addEventListener('submit', handleInputSubmit);
