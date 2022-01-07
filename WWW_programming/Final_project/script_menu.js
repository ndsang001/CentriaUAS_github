if (document.readyState == "loading") {
    document.addEventListener('DOMContentLoaded', ready)
} else {
    ready()
}

function ready() {
    var addToCartButtons = document.getElementsByClassName('shop-item-button')
    for (let i = 0; i < addToCartButtons.length; ++i) {
        var button = addToCartButtons[i]
        button.addEventListener('click', addToCartClicked)
    }
}

function addToCartClicked(event) {
    var button = event.target
    var shopItem = button.parentElement.parentElement
    var itemName = shopItem.getElementsByClassName('name_of_item')[0].innerText
    var itemPrice = shopItem.getElementsByClassName('price')[0].innerText
    var itemImage = shopItem.getElementsByClassName('item_image')[0].src
    console.log(itemName, itemPrice, itemImage)
    addItemToCart(itemName, itemPrice, itemImage)
}

function addItemToCart(itemName, itemPrice, itemImage) {
    var cartRow = document.createElement('div')
    cartRow.classList.add('cart_row')
    var cartItems = document.getElementsByClassName('cart_items')[0]
    var cartItemNames = cartItems.getElementsByClassName('cart_item_title')
    for (let i = 0; i < cartItemNames.length; ++i) {
        if (cartItemNames[i].innerText == itemName) {
            alert('This item is already added to the cart')
            return
        }
    }
    var cartRowContents = `
        <div class="cart_item cart_column">
            <img class="cart_item_image" src="${itemImage}" width="100" height="100">
            <span class="cart_item_title">${itemName}</span>
        </div>
            <span class="cart_price cart_column">${itemPrice}</span>
        <div class="cart_quantity cart-column">
            <input class="cart_quantity_input" type="number" value="1">
            <button class="btn btn-danger" type="button">REMOVE</button>
        </div>`

    cartRow.innerHTML = cartRowContents
    cartItems.append(cartRow)
}